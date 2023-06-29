#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll n; std::cin >> n;
  int grid [3][n];
  std::map<int,int> map;
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < n; ++j)
      std::cin >> grid[i][j];
  int ans = 0;
  for(int i = 0 ; i < n; ++i) map[grid[0][i]]++;
  for(int i = 0; i < n; ++i) ans += map[grid[1][grid[2][i]-1]];
  std::cout << ans;
}