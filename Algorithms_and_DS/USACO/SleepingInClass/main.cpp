#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int n; std::cin >> n;
    std::vector<int> prefix(n+1,0);
    for(int i = 0; i < n; ++i)
    {
      int val; std::cin >> val;
      prefix[i+1]=prefix[i]+val;
    }
    for (int k = n; k >= 1; k--) {
      if (prefix[n] % k == 0) {
        int targetSum = prefix[n] / k, left = 0;
        bool check = true;
        for (int right = 0; right < n+1; right++) {
          int currentSum = prefix[right]-prefix[left];
          if (currentSum > targetSum) {
            check = false;
            break;
          }
          if (currentSum == targetSum) left=right;
        }
        if (check) {std::cout << n - k << "\n";break;}
      }
    }
  }
}