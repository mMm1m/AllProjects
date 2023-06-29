#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll t; std::cin >> t;
  while(t--)
  {
    ll n; std::cin >> n;
    std::vector<ll> a(n), b(n), sum(n+1), cnt(n + 1), add(n + 1);
    for(auto& x : a) std::cin >> x; for(auto& x : b) std::cin >> x;
    for(int i = 0; i < n; i++)
      sum[i+1] = sum[i]+b[i];
    for(int i = 0; i < n; ++i)
    {
      ll j = std::upper_bound(sum.begin(),sum.end(),a[i]+sum[i])-sum.begin()-1;
      ++cnt[i]; --cnt[j];
      add[j] += (a[i]-(sum[j]-sum[i]));
    }
    for (int i = 0; i < n; ++i) {
      std::cout << cnt[i] * b[i] + add[i] << ' ';
      cnt[i + 1] += cnt[i];
    }
    std::cout << '\n';
  }
}
