#include <bits/stdc++.h>

int main()
{
  freopen("maxcross.in","r",stdin);
  freopen("maxcross.out","w",stdout);
  int n,k,b; std::cin >> n >> k >> b;
  std::vector<int> v(n,0), prefix(n+1,0);
  for(int i = 0; i < b; ++i)
  { int val; std::cin >> val; ++v[val-1];}
  for(int i = 1; i <= n; ++i)
  {
    prefix[i]=prefix[i-1];
    prefix[i] += v[i-1];
  }
  int ans = 1e9;
  for(int i = 0; i <= n-k; ++i)
    ans = std::min(ans,prefix[i+k]-prefix[i]);
  std::cout << ans;
}
