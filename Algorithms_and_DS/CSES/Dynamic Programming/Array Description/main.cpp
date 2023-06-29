#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9+7;

int main()
{
  ll n,m;
  std::cin >> n >> m;
  std::vector<ll> values(n);
  for(auto& a : values)
    std::cin >> a;
  std::vector<std::vector<ll>> pos_val(n, std::vector<ll>(m+1,0));
  if(values[0]!=0)
  {
    pos_val[0][values[0]] = 1;
  }
  else
  {
    for(int i = 1; i <= m; i++)
      pos_val[0][i] = 1;
  }
  for(int i = 1; i < n; i++)
  {
    if(values[i]==0)
    {
      for(int j = 1; j <= m; j++)
      {
        if(j >= 2)
          pos_val[i][j] = (pos_val[i][j] + pos_val[i-1][j-1])%MOD;
        if(j <= m-1)
          pos_val[i][j] = (pos_val[i][j] + pos_val[i-1][j+1])%MOD;
        pos_val[i][j] = (pos_val[i][j] + pos_val[i-1][j])%MOD;
      }
    }
    else
    {
      if(values[i]>=2)
        pos_val[i][values[i]] = (pos_val[i][values[i]] + pos_val[i-1][values[i]-1])%MOD;
      if(values[i]<=m-1)
        pos_val[i][values[i]] = (pos_val[i][values[i]] + pos_val[i-1][values[i]+1])%MOD;
      pos_val[i][values[i]] = (pos_val[i][values[i]] + pos_val[i-1][values[i]])%MOD;
    }
  }
  ll ans = 0, i = n-1;
    for(int j = 1; j <= m; j++)
      ans = (ans + pos_val[i][j])%MOD;
  std::cout << ans;
}