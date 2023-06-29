#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--) {
    int n, k1, k2, w, b;
    std::cin >> n >> k1 >> k2;
    std::cin >> w >> b;
    if (k1 + k2 >= 2 * w && (n - k1) + (n - k2) >= 2 * b)
      std::cout << "YES" << '\n';
    else
      std::cout << "NO" << '\n';
  }
}
