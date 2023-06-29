#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    std::vector<int> v(n), dp(n); dp[0]=0; dp[1]=0;
    for(auto& a : v) std::cin >> a;
    if(n==1) {
      std::cout << 0 << '\n';
      continue;
    }
    else
    {
      if(n==2&&v[1]>v[0]) {
        std::cout << 0 << '\n';
        continue;
      }
      else if(n==2&&v[0]>v[1]) {
        std::cout << 1 << '\n';
        continue;
      }
      else
        for(int i=2; i<n; i++)
        {
          dp[i-1]=std::max(dp[i-1],dp[i-2]+(v[i-1]>v[i]));
        }
    }
    std::cout << dp[n-2] << '\n';
  }
}
