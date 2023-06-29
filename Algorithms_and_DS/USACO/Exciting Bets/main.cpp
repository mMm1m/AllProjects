#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll t; std::cin >> t;
  while(t--)
  {
    ll a,b; std::cin >> a >> b;
    if(a==b) std::cout << 0 << " " << 0 << '\n';
    else
    {
      ll l=std::abs(a-b);
      ll m = std::min(a%l,l-a%l);
      std::cout <<  l << " " << m << '\n';
    }
  }
}
