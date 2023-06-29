#include <bits/stdc++.h>
using ll = long long;

struct Cow
{
  int day, cow, gallon;
  Cow(int d, int c, int g)
  {
    day = d;
    cow = c;
    gallon = g;
  }
};

int main()
{
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);
  int n, m;
  std::cin >> n >> m;
  std::vector<Cow> vector;
  std::map<int,int> map;
  for(int i = 0; i < n; i++)
  {
    int d, c, g;
    std::cin >> d >> c >> g;
    vector.push_back({Cow(d,c,g)});
    map[c] = m;
  }

  std::sort(vector.begin(), vector.end(), [](const Cow& c1, const Cow& c2){
    return c1.cow < c2.cow;
  });

  std::map<int, int> new_map{{m,n}};
  int ans = 0;
  for(int i = 0; i < vector.size(); i++)
  {
    auto curr = map[vector[i].cow];
    bool was_top = (curr == new_map.rbegin()->first);
    int prev_count = new_map[vector[i].cow];
    // remove the previous milk production number
    if (--new_map[curr] == 0)
      new_map.erase(curr);

    curr += vector[i].gallon;
    map[vector[i].cow] = curr;
    new_map[curr]++;

    bool is_top = (curr == new_map.rbegin()->first);
    int curr_count = new_map[curr];
    if(was_top) {
      if (is_top && curr_count == prev_count) continue;
      ans++;
    }
    else if(is_top)
      ans++;
  }

  std::cout << ans;

  /*for(int i = 0; i < vector.size(); i++)
  {
    for(auto it = map.begin(); it != map.end(); it++)
      std::cout << it->first << " " << it->second << '\n';
    std::cout << '\n';
  }

  for(auto& a : vector)
    std::cout << a.day << " " << a.cow << " " << a.gallon << '\n';

  for(auto it = map.begin(); it != map.end(); it++)
    std::cout << it->first << " " << it->second << '\n';*/
}
