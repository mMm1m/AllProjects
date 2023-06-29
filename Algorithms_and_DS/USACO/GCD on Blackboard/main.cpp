#include <bits/stdc++.h>

const int MAX = 1e6;
int main()
{
  int n; std::cin >> n;
  std::vector<int> v(n+1); for(int i = 1; i <= n; ++i) std::cin >> v[i];
  std::vector<int> prefix(10,0), suffix(10,0);

  for(int i = 1; i <= n; ++i)
    prefix[i]=std::gcd(prefix[i-1],v[i]);
  for(int i = n; i >= 1; --i)
    suffix[i]=std::gcd(suffix[i+1],v[i]);

  int ans = 0;
  for(int i = 1; i <= n; ++i)
    ans = std::max(ans,std::gcd(prefix[i-1],suffix[i+1]));
  std::cout << ans;
}
