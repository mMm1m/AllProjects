#include <bits/stdc++.h>

int main()
{
  int n,k; std::cin >> n >> k;
  std::vector<std::vector<int>> v(n+2*k,std::vector<int>(n+2*k,0)),prefix(n,std::vector<int>(n,0));

  for(int i = k; i < n+k; ++i)
    for (int j = k; j < n + k; ++j)
      std::cin >> v[i][j];

  for(int i = k; i < n+k; ++i) {
    for (int j = k; j < n + k; ++j) {
      // west to east
      int val = 0;
      for (int m = j - k; m <= j + k; ++m) val += v[i][m];
      // north to south
      for (int m = i - k; m <= i + k; ++m) val += v[m][j];
      // west to north
      int col = j, row = i;
      for(int m = 1; m <= k; ++m)
      {
        col--;
        while(col < j)
        {
          ++col; ++row;
          val +=
        }
      }

      // east to north



      // west to south



      // east to south



      prefix[i - k][j - k] = val-v[i][j];
    }
  }
  for(int i = 0; i < n; ++i)
  {
    for(int j = 0; j < n; ++j)
    {
      std::cout << prefix[i][j] << " ";
    }
    std::cout << '\n';
  }
}
