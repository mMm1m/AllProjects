#include <bits/stdc++.h>
using ll = long long;

int main()
{
  freopen("div7.in","r",stdin);
  freopen("div7.out","w",stdout);
  ll n; std::cin >> n;
  std::vector<ll> v(n), prefix(n+1);
  for(auto& a : v) std::cin >> a;
  for(ll i = 1; i <= n; ++i)
    prefix[i]=prefix[i-1]+v[i-1];
  ll max = 0;
  for(ll right = 0; right <= n; ++right)
  {
    for(ll left = 0; left <= right; ++left)
    {
      if((prefix[right]-prefix[left])%7==0)
        max = std::max(right-left,max);
    }
  }
  std::cout << max;
}
