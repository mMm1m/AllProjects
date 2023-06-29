#include <bits/stdc++.h>
using ll = long long;

const ll MOD = 1e9+7;


int main() {
  ll n;
  std::cin >> n;
  ll target = n*(n+1)/2;
  if (target%2) {
    std::cout << 0 << '\n';
    return 0;
  }
  target /= 2;

  std::vector<std::vector<ll>> dp(n,std::vector<ll>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      if (j >= i)
        (dp[i][j] += dp[i-1][j-i]) %= MOD;
    }
  }
  std::cout << dp[n-1][target] << '\n';
}