#include <bits/stdc++.h>

int main()
{
  //freopen(" balancing.in","r",stdin);
  //freopen(" balancing.out","w",stdout);
  int n,b; std::cin >> n >> b;
  std::vector<int> x(n),y(n);
  for(int i = 0; i < n; ++i)
  {
    int x_,y_; std::cin >> x_ >> y_;
    x[i]=x_; y[i]=y_;
  }
  int ans = n;
  for(int i = 0; i < n; ++i)
  {
    for(int j = 0; j < n; ++j)
    {
      int x_fence = x[i]+1;
      int y_fence = y[j]+1;
      int up_left = 0, up_right = 0, low_left = 0, low_right = 0;
      for(int k = 0; k < n; ++k)
      {
        if(x[k]>x_fence && y[k]>y_fence) ++up_right;
        if(x[k]<x_fence && y[k]>y_fence) ++up_left;
        if(x[k]>x_fence && y[k]<y_fence) ++low_right;
        if(x[k]>x_fence && y[k]>y_fence) ++low_left;
      }
      int worstRegion = 0;
      if(up_left > worstRegion) worstRegion = up_left;
      if(up_right > worstRegion) worstRegion = up_right;
      if(low_left > worstRegion) worstRegion = low_left;
      if(low_right > worstRegion) worstRegion = low_right;
      if(worstRegion < ans) ans = worstRegion;
    }
  }
  std::cout << ans;
}