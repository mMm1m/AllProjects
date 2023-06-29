#include <bits/stdc++.h>

int main()
{
  int n,k;
  std::cin >> n >> k;
  std::vector<std::vector<char>> original(k,std::vector<char>(n));
  std::vector<std::vector<char>> transpanation(n,std::vector<char>(k));
  for(int i = 0; i < k; i++)
    for(int j = 0; j < n; j++)
      std::cin >> original[i][j];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < k; j++)
      transpanation[i][j] = original[j][i];

  for(int i = 0; i < n; i++)
  {
    for(int l = 0; l < 2; l++) {
      for (int j = 0; j < k; j++) {
        std::cout << transpanation[i][j] << transpanation[i][j];
      }
      std::cout << '\n';
    }
  }

}
