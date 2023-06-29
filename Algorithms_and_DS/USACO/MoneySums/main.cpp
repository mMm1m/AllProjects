#include <bits/stdc++.h>
using ll = long long;

int main() {
  ll n;
  std::cin >> n;
  ll max_sum = n*1000;
  std::vector<ll> x(n);
  for (auto&v : x)
    std::cin >> v;
  std::vector<std::vector<bool>> dp(n+1,std::vector<bool>(max_sum+1,false));
  dp[0][0] = true;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 0; j <= max_sum; j++) {
      dp[i][j] = dp[i-1][j];
      ll left = j-x[i-1];
      if (left >= 0 && dp[i-1][left])
        dp[i][j] = true;
    }
  }
  std::vector<ll> possible;
  for (int j = 1; j <= max_sum; j++)
    if (dp[n][j])
      possible.push_back(j);
  std::cout << possible.size() << '\n';
  for (auto& v : possible)
    std::cout << v << ' ';
  std::cout << '\n';
  /*for(int i = 0; i <= n; i++)
  {
    for(int j = 0; j <= max_sum; j++)
    {
      std::cout << dp[i][j] << " ";
    }
    std::cout << '\n';
  }*/
}
