#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll n,x;
  std::cin >> n >> x;
  std::map<ll,ll> map;
  for(int i = 0; i < n; i++) {
    ll val;
    std::cin >> val;
    if (map.count(x - val)) {
      std::cout << i + 1 << " " << map[x - val] << '\n';
      return 0;
    }
    map[val] = i + 1;
  }
  std::cout << "IMPOSSIBLE";
}