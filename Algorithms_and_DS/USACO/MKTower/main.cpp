#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int n; std::cin >> n;
    std::vector<int> v(n); for(auto& a : v) std::cin >> a;
    std::vector<std::vector<int>> dp(2,std::vector<int>(n+1,1e9));
    dp[1][0]=0;
    for(int j = 0; j < n; j++)
    {
      // me
      if(j<=n-1)
        dp[0][j+1]=std::min(dp[0][j+1],dp[1][j]+v[j]);
      if(j<=n-2)
        dp[0][j+2]=std::min(dp[0][j+2],dp[1][j]+v[j]+v[j+1]);
      // friend
      if(j<=n-1)
        dp[1][j+1]=std::min(dp[1][j+1],dp[0][j]);
      if(j<=n-2)
        dp[1][j+2]=std::min(dp[1][j+2],dp[0][j]);
    }
    std::cout << std::min(dp[0][n],dp[1][n]) << '\n';
  }
}
