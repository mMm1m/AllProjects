#include <bits/stdc++.h>

int main()
{
  int n,q; std::cin >> n >> q;
  std::vector<std::vector<char>> grid(n,std::vector<char>(n));
  std::vector<std::vector<int>> prefix(n+1,std::vector<int>(n+1,0));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      std::cin >> grid[i][j];

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+(grid[i-1][j-1]=='*');

  for(int i = 0; i < q; ++i)
  {
    int x1,y1,x2,y2; std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << prefix[x2][y2]+prefix[x1-1][y1-1]-prefix[x2][y1-1]-prefix[x1-1][y2] << '\n';
  }
}
