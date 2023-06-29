#include <bits/stdc++.h>
using ll = long long;

int main(){
  ll n, x;
  std::cin >> n >> x;
  std::vector<ll> coins(n);
  std::vector<ll> dp(x+1, INT_MAX);
  for (int i = 0; i < n; i++) {
    std::cin >> coins[i];
  }
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int weight = 0; weight <= x; weight++) {
      if(weight - coins[i - 1] >= 0) {
        dp[weight] = std::min(dp[weight], dp[weight - coins[i - 1]] + 1);
      }
    }
  }
  std::cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';
}