#include <bits/stdc++.h>

int main()
{
  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);
  int n, m;
  std::cin >> n >> m;
  std::vector< int > officer(105), bessie(105);
  int curr_road = 0, start = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    curr_road += a;
    for (int j = start; j < curr_road; ++j)
      officer[j] = b;
    start = curr_road;
  }

  curr_road = 0, start = 0;
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    curr_road += a;
    for (int j = start; j < curr_road; ++j)
      bessie[j] = b;
    start = curr_road;
  }
  int max = 0;
  for (int i = 0; i < 100; ++i) {
    if (bessie[i] > officer[i])
      max = std::max(max, (bessie[i] - officer[i]));
  }
  std::cout << max << '\n';
}