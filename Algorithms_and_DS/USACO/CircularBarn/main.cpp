#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e10;

int main()
{
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);
  ll n,min = MOD; std::cin >> n;
  std::vector<ll> v(n);
  for(auto& a : v) std::cin >> a;
  for(ll i = 0; i < n; ++i)
  {
    ll j = i, curr = 0, c= 0; ++j;
    while(j%n!=i)
    {
      curr += v[j%n]*(++c);
      ++j;
    }
    min = std::min(min,curr);
  }
  std::cout << min;
}
