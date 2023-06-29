#include <bits/stdc++.h>

int main()
{
  int n,m;
  std::cin >> n >> m;
  std::vector<int> dp(n,1e9); dp[0]=0;
  std::string str; std::cin >> str;
  for(int i=0; i<n; i++)
    if(str[i]=='1')
      for(int j=0; j<=m; j++)
        if(i+j<n && str[i+j]=='1')
          dp[i+j]=std::min(dp[i+j],dp[i]+1);
  if(dp[n-1]==1e9) std::cout << -1;
  else std::cout << dp[n-1];
}
