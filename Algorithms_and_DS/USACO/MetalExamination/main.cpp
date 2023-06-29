#include <bits/stdc++.h>
using ll = long long;

int main() {
  ll n;
  std::cin >>  n;
  std::vector<ll> v(n);
  for(int i = 0; i < n; i++)
  {
    ll val;
    std::cin >> val;
    v[--val] = i;
  }
  ll left = n, right = 0, number = 1, ans = 0;
  for(int i = n-1; i >= 0; i--, number++)
  {
    left = std::min(left, v[i]);
    right = std::max(right, v[i]);
    ans = std::max(ans, right-left-number+3);
  }
  if(n==1)
  {
    std::cout << 1;
    return 0;
  }
  std::cout << ans;
}