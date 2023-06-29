#include <bits/stdc++.h>
using ll = long long;

ll gcd(ll a,ll b)
{
  return b==0 ? a : gcd(b,a%b);
}

int main()
{
  ll t; std::cin >> t;
  while(t--)
  {
    ll n; std::cin >> n;
    for(int a = 2; a <= n-2; ++a)
    {
      ll b = n-a-1;
      if(gcd(a,b)==1)
      {
        std::cout << a << " " << b << " " << 1 << '\n';
        break;
      }
    }
  }
}
