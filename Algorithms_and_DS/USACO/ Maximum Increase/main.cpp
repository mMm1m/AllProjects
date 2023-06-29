#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for(auto& a: v) std::cin >> a;
  std::vector<int> dp(n); dp[0] = 1;
  for(int i = 1; i < n; i++)
  {
    dp[i] = dp[i-1];
    if(v[i]>v[i-1]) ++dp[i];
    else dp[i]=1;
  }
  int max = 0;
  for(auto& a : dp)
    max = std::max(max, a);
  std::cout << max;
}
