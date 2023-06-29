#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll t; std::cin >> t;
  while(t--)
  {
    ll n; std::cin >> n;
    std::string str; std::cin >> str;
    std::vector<ll> prefix(n+1);
    for(int i = 1; i <= n; ++i)
    {
      prefix[i] = str[i-1]-'0';
      prefix[i] += prefix[i-1];
    }
    std::map<ll,ll> map;
    for(ll i = 0; i <= n; ++i) ++map[prefix[i]-i];
    ll ans = 0;
    for(auto& a : map) ans += a.second*(a.second-1)/2;
    std::cout << ans << '\n';
  }
}
