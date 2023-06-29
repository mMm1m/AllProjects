#include <bits/stdc++.h>

int main() {
  int n, k;
  std::cin >> n >> k; // max price &  number of books
  std::vector<int> price(n); // vector of prices
  std::vector<int> pages(n); // vector of pages
  std::vector<std::vector<int>> dp(n+1,std::vector<int>(k+1,0));
  // result vector of vectors
  for(int i = 0; i < n; i++) std::cin >> price[i];
  for(int i = 0; i < n; i++) std::cin >> pages[i];
  for(int i = 1; i <= n; i++) // for numbers
  {
    for(int j = 0; j <= k; j++) // for prices
    {
      dp[i][j] = dp[i-1][j];
      if(j-price[i-1] >= 0)
        dp[i][j] = std::max(dp[i][j],dp[i-1][j-price[i-1]]+pages[i-1]); // don't forget add pages in second param
    }
  }
  std::cout << dp[n][k];
  return 0;
}