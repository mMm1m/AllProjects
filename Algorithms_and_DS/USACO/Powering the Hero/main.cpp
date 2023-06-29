#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll t; std::cin >> t;
  while(t--)
  {
    ll n, ans = 0; std::cin >> n;
    std::priority_queue<ll> pq;
    for(int i = 0; i < n; ++i)
    {
      ll val; std::cin >> val;
      if(val > 0)
        pq.push(val);
      else
      {
        if(!pq.empty()) {
          ans += pq.top();
          pq.pop();
        }
      }
    }
    std::cout << ans << '\n';
  }
}
