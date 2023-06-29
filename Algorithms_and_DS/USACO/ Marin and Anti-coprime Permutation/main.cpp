#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 998244353;

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> fact(1e3+5); fact[0]=1; fact[1]=1;
  for(int i=2; i<=1e3+5;i++ )
  {fact[i] = fact[i-1]*i; }
  while(n--)
  {
    int t; std::cin >> t;
    if(t%2==1) std::cout << 0 << '\n';
    else
    {
      long long ans = 1;
      for (int i = 1; i <= t / 2; ++i) {
        ans *= 1LL * i * i % MOD;
        ans %= MOD;
      }
      std::cout << ans << '\n';
    }
  }
}
