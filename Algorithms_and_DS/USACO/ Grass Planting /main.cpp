#include <bits/stdc++.h>

int main()
{

  freopen("planting.in","r",stdin);
  freopen("planting.out","w",stdout);
  int n; std::cin >> n;
  std::vector<int> v(n+1);
  for(int i = 0; i < n-1; ++i)
  {
    int a,b; std::cin >> a >> b;
    ++v[a]; ++v[b];
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i)
    ans = std::max(ans, v[i]+1);
  std::cout << ans;
}
