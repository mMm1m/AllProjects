#include <bits/stdc++.h>
using ll = long long;

const ll MOD = 1e9;

int main()
{
  ll n,k, ans, count = 0; std::cin >> n >> k;
  std::vector<ll> v(n); for(auto& a : v) std::cin >> a;
  std::sort(v.begin(), v.end());
  if(k==0) ans = v[0]-1;
  else ans = v[k-1];

  for(int i = 0; i < n; ++i)
    if(v[i]<=
    ans) ++count;
  if(count != k || !(ans >= 1 && ans <= 1e9))
  {std::cout << -1 << '\n'; return 0;}
  std::cout << ans << '\n';
}