#include <bits/stdc++.h>

int main()
{
  int n,k;
  std::cin >> n >> k;
  std::multiset<int> chicken;
  std::vector<std::pair<int, int>> cow(k);
  for(int i = 0; i < n; i++)
  {
    int val;
    std::cin >> val;
    chicken.insert(val);
  }
  for(int i = 0; i < k; i++)
    std::cin >> cow[i].first >> cow[i].second;
  std::sort(cow.begin(), cow.end());

  int ans = 0;
  for(int i = 0; i < k; i++)
  {
    auto it = chicken.lower_bound(cow[i].second);
    if(it != chicken.end()  && *it <= cow[i].first)
    {
      ans++;
      chicken.erase(it);
    }
  }
  std::cout << ans;
}
