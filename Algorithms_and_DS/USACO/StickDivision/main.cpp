#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll x, n;
  std::cin >> x >> n;
  std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
  for(int i = 0; i < n; i++)
  {
    ll val;
    std::cin >> val;
    pq.push(val);
  }

  ll answer = 0;
  for(int i = 1; i < n; i++)
  {
    ll a = pq.top(); pq.pop();
    ll b = pq.top(); pq.pop();
    pq.push(a+b);
    answer += (a+b);
  }
  std::cout << answer;
}
