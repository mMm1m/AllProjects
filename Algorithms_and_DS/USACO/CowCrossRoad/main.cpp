#include <bits/stdc++.h>

int main()
{
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> vector(n);
  for(int i = 0; i < n; i++)
    std::cin >> vector[i].first >> vector[i].second;
  std::sort(vector.begin(), vector.end());
  int total = 0;
  for(int i = 0; i < n; i++)
  {
    if(vector[i].first >= total)
      total = vector[i].first;
    else
      vector[i].first = total;
    total += vector[i].second;
  }
  std::cout << total;
  return 0;
}
