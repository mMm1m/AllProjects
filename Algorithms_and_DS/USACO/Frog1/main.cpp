#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> v(n), dp(n+1, 1e9);
  dp[1] = 0;
  for(auto& a : v) std::cin >> a;
  for(int i = 1; i <= n; i++)
  {
    if(i <= n-1)
      dp[i+1]=std::min(dp[i+1],dp[i]+std::abs(v[i+1]-v[i]));
    if(i <= n-2)
      dp[i+2]=std::min(dp[i+2],dp[i]+std::abs(v[i+2]-v[i]));
  }
  std::cout << dp[n-1] << '\n';
}
