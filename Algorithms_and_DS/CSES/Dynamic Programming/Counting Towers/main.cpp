#include <bits/stdc++.h>
using ll = long long;

const ll MOD = 1e9 + 7;

int main()
{
    std::vector<std::vector<ll>> dp(1000000,std::vector<ll>(2,0));
    dp[0][0] = 1; dp[0][1] = 1;
    for(int i = 1; i < 1000000; i++)
    {
      dp[i][0] = ((2*dp[i-1][0])%MOD + (dp[i-1][1])%MOD)%MOD;
      dp[i][1] = ((dp[i-1][0])%MOD + (4*dp[i-1][1])%MOD)%MOD;
    }

  ll t;
  std::cin >> t;
  while(t--)
  {
    ll n;
    std::cin >> n;
    std::cout << ((dp[n-1][0])%MOD + (dp[n-1][1])%MOD)%MOD << '\n';
  }
}