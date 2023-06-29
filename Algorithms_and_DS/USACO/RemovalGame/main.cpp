#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll n, sum = 0;
  std::cin >> n;
  std::vector<ll> values(n);
  for(auto& a : values)
  {
    std::cin >> a;
    sum += a;
  }
  std::vector<std::vector<ll>> dp(n, std::vector<ll>(n,0));
  for(ll i = n-1; i >= 0; i--)
  {
    for(ll j = i; j < n; j++)
    {
      if(i==j)
        dp[i][j] = values[i];
      else
        dp[i][j] = std::max(values[i]-dp[i+1][j],values[j]-dp[i][j-1]);
    }
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      std::cout << dp[i][j] << " ";
    }
    std::cout << '\n';
  }
  std::cout << (sum+dp[0][n-1])/2;
}
