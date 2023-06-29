#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  std::map<int,int> map;
  for(auto & a : v)
  {
    std::cin >> a;
    map[a]++;
  }
  int t;
  std::cin >> t;
  std::sort(v.begin(), v.end());
  int ans = 0;
  for(int i = 0; i < n; i++)
  {
    int count = 0;
    for(int k = v[i]; k <= v[i]+t; k++)
      count += map[k];
    ans = std::max(ans, count);
  }
  std::cout << ans;
}
