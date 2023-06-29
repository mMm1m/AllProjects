#include <bits/stdc++.h>

int main()
{
  freopen("cowtip.in","r",stdin);
  freopen("cowtip.out","w",stdout);
  int n; std::cin >> n;
  std::vector<std::string> grid(n);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      std::cin >> grid[i][j];
  int cnt = 0;
  for(int i = n-1; i >= 0; --i)
  {
    for(int j = n-1; j >= 0; --j)
    {
      if(grid[i][j]=='1')
      {
        ++cnt;
        for(int k = 0; k <= i; ++k)
        {
          for(int m = 0; m <= j; ++m)
          {
            grid[k][m]=='0' ? grid[k][m]='1' : grid[k][m]='0';
          }
        }
      }
    }
  }
  std::cout << cnt;
}
