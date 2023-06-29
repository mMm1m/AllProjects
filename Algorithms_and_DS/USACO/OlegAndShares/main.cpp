#include <bits/stdc++.h>
using ll = long long;

int main()
{
  int n,k;
  std::cin >> n >> k;
  std::vector<int> v(n);
  for(auto& a : v)
    std::cin >> a;
  std::sort(v.begin(), v.end());
  ll ans = 0;
  for(int i = 0; i < n; i++)
  {
    int a = (v[i]-v[0])%k, b =  (v[i]-v[0])/k;
    if(a==0) {
      ans += b;
    }
    else {
      std::cout << -1;
      return 0;
    }
  }
  std::cout << ans;
}
