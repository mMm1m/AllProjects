#include <bits/stdc++.h>

int main() {
  int n, k; std::cin >> n >> k;
  std::vector<int> diff(n + 1);
  for (int i = 0; i < k; i++) {
    int l, r; std::cin >> l >> r;
    l--; r--;
    diff[l]++; diff[r + 1]--;
  }
  int sol[1000000], tot = 0;
  for (int i = 0; i < n; i++)
  {
    tot += diff[i];
    sol[i] = tot;
  }
  std::sort(sol, sol + n);
  std::cout << sol[n / 2] << '\n';
}
