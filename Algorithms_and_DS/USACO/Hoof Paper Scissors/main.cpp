#include <bits/stdc++.h>

int main()
{
  freopen("hps.in","r",stdin);
  freopen("hps.out","w",stdout);
  int n; std::cin >> n;
  std::vector<int> h(n+1),p(n+1),s(n+1);
  for(int i = 1; i <= n; ++i)
  {
    char val; std::cin >> val;
    p[i]=p[i-1]; h[i]=h[i-1]; s[i]=s[i-1];
    if(val=='P') p[i]++;
    else if(val=='H') h[i]++;
    else if(val=='S') s[i]++;
  }
  int ans=  0;
  for(int i = 1; i <= n;++i)
  {
    int prefix = std::max({p[i],h[i],s[i]});
    int suffix = std::max({std::abs(p[n]-p[i]),std::abs(h[n]-h[i]),std::abs(s[n]-s[i])});
    ans = std::max(ans,suffix+prefix);
  }
  std::cout << ans;
}

