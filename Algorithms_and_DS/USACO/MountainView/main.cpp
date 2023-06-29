#include <bits/stdc++.h>
using ll = long long;

struct Mountain
{ll left,right;};

int main()
{
  freopen("mountains.in","r",stdin);
  freopen("mountains.out", "w", stdout);
  std::vector<Mountain> v;
  ll n; std::cin >> n;
  for(ll i = 0; i < n; ++i)
  {
    ll a,b; std::cin >> a >> b;
    ll left = a-b, right = a+b;
    Mountain c; c.left = left; c.right=right;
    v.push_back(c);
  }
  std::sort(v.begin(), v.end(), [](const Mountain& m1, const Mountain& m2){
    if(m1.left == m2.left)
      return m1.right > m2.right;
    return m1.left < m2.left;
  });
  ll ans = 0, right = -1;
  for(auto& a : v)
  {
    if(a.right > right)
    {
      ++ans;
      right  = a.right;
    }
  }
  std::cout << ans;
}