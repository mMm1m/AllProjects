#include <bits/stdc++.h>
using ll = long long;

bool cmp_x(const std::pair<ll,ll>& p1, const std::pair<ll,ll>& p2)
{
  return p1.first < p2.first;
}

bool cmp_y(const std::pair<ll,ll>& p1, const std::pair<ll,ll>& p2)
{
  return p2.first < p2.second;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::pair<ll,ll>> vector(n);
  std::set<ll> Y,X;
  for(int i = 0; i < n; i++)
    std::cin >> vector[i].first >> vector[i].second;

  std::map<ll,ll> map_x;
  std::map<ll,ll> map_y;
  std::sort(vector.begin(), vector.end(), cmp_x);
  for(int i = 0; i < n; i++)
    map_x[vector[i].first] = i;
  std::sort(vector.begin(), vector.end(), cmp_y);
  for(int i = 0; i < n; i++)
    map_y[vector[i].second] = i;

  std::sort(vector.begin(), vector.end(), cmp_x);

  // make our prefix sums for the y-lines
  std::vector<std::vector<int>> lt_y(n, std::vector<int>(n + 1));
  std::vector<std::vector<int>> gt_y(n, std::vector<int>(n + 1));
  for (int c = 0; c < n; c++) {
    int curr_y = vector[c].second;
    for (int x = 1; x <= n; x++) {
      lt_y[curr_y][x] = (
        lt_y[curr_y][x - 1] + (vector[x - 1].second < curr_y)
      );
      gt_y[curr_y][x] = (
        gt_y[curr_y][x - 1] + (vector[x - 1].second > curr_y)
      );
    }
  }
  long long total = 0;
  for (int c1 = 0; c1 < n; c1++) {
    for (int c2 = c1 + 1; c2 < n; c2++) {
      int bottom = std::min(vector[c1].second, vector[c2].second);
      int top = std::max(vector[c1].second, vector[c2].second);
      int bottom_total = 1 + lt_y[bottom][c2 + 1] - lt_y[bottom][c1];
      int top_total = 1 + gt_y[top][c2 + 1] - gt_y[top][c1];
      total += (long long) bottom_total * top_total;
    }
  }
  total += n + 1;
  std::cout << total << "\n";
}