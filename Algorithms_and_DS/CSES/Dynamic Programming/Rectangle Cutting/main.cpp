#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll a,b;
  std::cin >> a >> b;
  if(a==b)
  {
    std::cout << 0;
    return 0;
  }
  std::vector<std::vector<ll>> dp(a+1, std::vector<ll>(b+1));
  for(int i = 0; i <= a; i++)
  {
    for(int j = 0; j <= b; j++)
    {
      if(i==j) dp[i][j] = 0;
      else dp[i][j] = 1e9;
      for(int tmp = 1; tmp < i; tmp++)
        dp[i][j] = std::min(dp[i][j], dp[i-tmp][j]+dp[tmp][j]+1);
      for(int tmp = 1; tmp < j; tmp++)
        dp[i][j] = std::min(dp[i][j], dp[i][j-tmp]+dp[i][tmp]+1);
    }
  }
  std::cout << dp[a][b];
}