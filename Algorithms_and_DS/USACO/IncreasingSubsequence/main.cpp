#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll n;
  std::cin >> n;
  std::vector<ll> v;
  for(int i = 0; i < n; i++)
  {
    ll val;
    std::cin >> val;
    auto it = lower_bound(v.begin(), v.end(),val);
    if(it == v.end())
      v.push_back(val);
    else
      *it = val;
  }
  std::cout << v.size();
}

/*int main()
{
  ll n;
  std::cin >> n;
  std::vector<ll> arr(n);
  for(auto& a : arr)
    std::cin >> a;
  std::vector<ll> subs(n,0);
  for(int i = 0; i < n; i++)
  {
    subs[i] = 1;
    for(int j = 0; j < i; j++)
    {
      if(i > j && arr[i] > arr[j])
        subs[i] = std::max(subs[i], subs[j]+1);
    }
  }
  ll ans = 0;
  for(auto& a : subs)
    ans = std::max(ans, a);
  std::cout << ans;
}*/
