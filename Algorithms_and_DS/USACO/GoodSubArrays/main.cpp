#include <bits/stdc++.h>
using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> pref_arr(n + 1);
  for (int i = 1; i <= n; i++) {
    char c;
    std::cin >> c;
    pref_arr[i] = c - '0';
  }
  for (int i = 1; i <= n; i++) {
    pref_arr[i] += pref_arr[i - 1];
  }
  std::map<int, ll> sum_dist;
  for (int i = 0; i <= n; i++) {
    sum_dist[pref_arr[i] - i]++;
  }
  ll good_arrays = 0;
  for (const auto& [_, f]: sum_dist) {
    // calculate # of possible unordered pairs with f values of i
    good_arrays += f * (f - 1) / 2;
  }
  std::cout << good_arrays << "\n";
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}