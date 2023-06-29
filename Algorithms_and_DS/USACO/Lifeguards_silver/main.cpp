#include <bits/stdc++.h>

struct Cow
{
  int l, r;
};
bool operator<(const Cow &a, const Cow &b) { return a.l < b.l; }

int main() {

  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdin);
  int n; std::cin >> n;
  std::vector<Cow> cows(n);
  for (int i = 0; i < n; i++) { std::cin >> cows[i].l >> cows[i].r; }
  sort(cows.begin(), cows.end());
  int total_time = 0, left = 0, right = 0;
  for (int i = 0; i < n; i++) {
    if (cows[i].r > right) {
      left = std::max(right, cows[i].l);
      total_time += cows[i].r - left;
      right = cows[i].r;
    }
  }

  Cow last;
  last.l = cows[n - 1].r;
  cows.push_back(last);
  int min_alone_time = total_time;
  right = 0;
  for (int i = 0; i < n; i++) {
    int curr_res = std::min(cows[i + 1].l, cows[i].r) - std::max(cows[i].l, right);
    min_alone_time = std::min(min_alone_time, curr_res);
    right = std::max(right, cows[i].r);
  }
  std::cout << total_time << " " << total_time - std::max(min_alone_time, 0) << '\n';
}
