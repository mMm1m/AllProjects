#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector< int > dp(n + 1, 1E9);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int temp = i;
    while (temp > 0) {
      dp[i] = std::min(dp[i], dp[i - temp % 10] + 1);
      temp /= 10;
    }
  }
  std::cout << dp[n];
}
