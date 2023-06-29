#include <bits/stdc++.h>

const int constanta = 1e3;

std::vector<std::vector<int>> graphic(constanta+1, std::vector<int>(constanta+1,0));

int main()
{
  freopen("paintbarn.in", "r", stdin);
  freopen("paintbarn.out", "w", stdout);
  int n, k;
  std::cin >> n >> k;
  for(int i = 0; i < n; i++)
  {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    ++graphic[x1][y1];
    --graphic[x1][y2];
    --graphic[x2][y1];
    ++graphic[x2][y2];
  }

  /*for(int i = 0; i < graphic.size(); i++) {
    for (int j = 0; j < graphic.size(); j++) {
      std::cout << graphic[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";*/

  int count = 0;
  for(int i = 0; i < constanta; i++)
  {
    for(int j = 0; j < constanta; j++) {
      if (i > 0) graphic[i][j] += graphic[i-1][j];
      if (j > 0) graphic[i][j] += graphic[i][j-1];
      if (i > 0 && j > 0) graphic[i][j] -= graphic[i-1][j-1];

      if(graphic[i][j] == k) count++;
    }
  }
  /*for(int i = 0; i < graphic.size(); i++) {
    for (int j = 0; j < graphic.size(); j++) {
      std::cout << graphic[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";*/

  std::cout << count;
}
