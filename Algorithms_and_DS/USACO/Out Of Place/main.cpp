#include <bits/stdc++.h>

int main()
{
  freopen("outofplace.in","r",stdin);
  freopen("outofplace.out","w",stdout);

  int n; std::cin >> n;
  std::vector<int> v(n); for(auto& a : v) std::cin >> a;
  if(n==1) {std::cout << 0; return 0;}
  else
  {
    auto vector = v;
    std::sort(vector.begin(), vector.end());
    int ans = 0;
    for(int i = 0; i < n; ++i)
      if(vector[i]!=v[i]) ++ans;
    std::cout << ans-1;
  }
}
