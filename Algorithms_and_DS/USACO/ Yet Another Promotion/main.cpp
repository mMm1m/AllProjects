#include <iostream>
using ll = long long;

int main()
{
  ll t; std::cin >> t;
  while(t--)
  {
    ll a,b,n,m; std::cin >> a >> b >> n >> m;
    ll q = n/(m+1), r = n-q*(m+1);
    ll ans = q*std::min(a*m,b*(m+1))+r*std::min(a,b);
    std::cout << ans << '\n';
  }
}
