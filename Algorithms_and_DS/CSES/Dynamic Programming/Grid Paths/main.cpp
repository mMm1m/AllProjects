#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9+7;

int main()
{
  ll n;
  std::cin >> n;
  std::vector< std::vector< ll>> v(n, std::vector< ll >(n, 0));
  v[0][0] = 1;
  for (int i = 0; i < n; i++) {
    std::string str;
    std::cin >> str;
    for (int j = 0; j < n; j++) {
      if (str[j] == '.')
      {
        if (i > 0)
        {
          v[i][j] += v[i - 1][j];
          v[i][j] %= MOD;
        }
        if (j > 0)
        {
          v[i][j] += v[i][j - 1];
          v[i][j] %= MOD;
        }
      }
      else
        v[i][j] = 0;
    }
  }
    std::cout << v[n - 1][n - 1];
}