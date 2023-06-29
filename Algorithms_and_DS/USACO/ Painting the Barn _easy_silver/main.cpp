#include <bits/stdc++.h>

const int MAX_SIZE = 10;

int main()
{
  freopen("paintbarn.in","r",stdin);
  freopen("paintbarn.out","w",stdout);
  int n, q;
  std::cin >> n >> q;
  std::vector< std::vector< int>> grid(MAX_SIZE, std::vector< int >(MAX_SIZE, 0));
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    ++grid[x1][y1];
    ++grid[x2][y2];
    --grid[x1][y2];
    --grid[x2][y1];
  }
  int ans = 0;
  for (int i = 0; i < MAX_SIZE; ++i) {
    for (int j = 0; j < MAX_SIZE; ++j) {
      if (i > 0) grid[i][j] += grid[i - 1][j];
      if (j > 0) grid[i][j] += grid[i][j - 1];
      if (i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1];
      ans += (grid[i][j] == 2);
    }
  }
  std::cout << ans;
}