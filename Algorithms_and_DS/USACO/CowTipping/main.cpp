#include <bits/stdc++.h>

int main()
{
  freopen("cowtip.in", "r", stdin);
  freopen("cowtip.out", "w", stdout);
  int n;
  std::cin >> n;
  int array_2D[n][n];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      std::cin >> array_2D[i][j];

  int count = 0;
  for(int i = n-1; i >= 0; i--)
  {
    for(int j = n-1; j >= 0; j--)
    {
      if(array_2D[i][j] == 1)
      {
        count++;
        for(int a = 0; a <= i; a++)
        {
          for(int b = 0; b <= j; b++)
          {
            if(array_2D[a][b] == 0)
              array_2D[a][b] = 1;
            else
              array_2D[a][b] = 0;
          }
        }
      }
    }
  }

  std::cout << count;
}
