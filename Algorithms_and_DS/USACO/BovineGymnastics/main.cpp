#include <bits/stdc++.h>

int main()
{
  freopen("cownomics.out","w",stdout);
  freopen("cownomics.in", "r", stdin);
  int n,m;
  std::cin >> n >> m;
  std::vector<std::vector<char>> spot(n, std::vector<char>(n));
  std::vector<std::vector<char>> no_spot(n, std::vector<char>(n));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      std::cin >> spot[i][j];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      std::cin >> no_spot[i][j];

  int pos = 0;
  for(int i = 0; i < m; i++)
  {
    bool val = true;
    for(int j = 0; j < n; j++)
    {
      for(int k = 0; k < n; k++)
      {
        if(spot[k][i] == no_spot[j][i])
        {
          val = false;
          break;
        }
      }
    }
    if(val)
      pos++;
  }
  std::cout << pos;
}
