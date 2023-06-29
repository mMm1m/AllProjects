#include <bits/stdc++.h>

int main()
{
  int n,k, MX = 1e5+5; std::cin >> n >> k;
  int dp[MX][25][3];
  std::vector<int> victory(n); std::vector<char> original(n);
  for(auto& a : original) std::cin >> a;
  for(int i =0 ; i < n; i++)
  {
    // h beat by p(0); p beat by s(1); s beat by h(2)
    if(original[i]=='H') victory[i]==0;
    if(original[i]=='P') victory[i]==1;
    if(original[i]=='S') victory[i]==2;
  }

  for(int i = 1; i < n; i++)
  {
    for(int j = 1; j <= k; j++)
    {
      for(int l = 0; l < 3; l++)
      {
        if(l==victory[i]) ++dp[i][j][l];
        dp[i][j][0] = std::max(dp[i][j][0], dp[i-1][j-1][l]);
        dp[i][j][1] = std::max(dp[i][j][1], dp[i-1][j-1][l]);
        dp[i][j][2] = std::max(dp[i][j][2], dp[i-1][j-1][l]);
        dp[i][j-1][l] = std::max(dp[i][j-1][l], dp[i-1][j][l]);
      }
    }
  }


  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < k; j++)
    {
      for(int l = 0; l < 3; l++)
      {
        std::cout << dp[i][j][l] << " ";
      }
    }
  }
}
