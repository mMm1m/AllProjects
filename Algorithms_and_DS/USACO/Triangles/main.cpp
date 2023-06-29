#include <bits/stdc++.h>

int main()
{
  freopen("triangles.in", "r", stdin );
  freopen("triangles.out", "w", stdout);
  int ans = 0, n; std::cin >> n;
  int x[n], y[n];
  for(int i = 0; i < n; ++i)
  {
    int x_,y_; std::cin >> x_ >> y_;
    x[i]=x_; y[i]=y_;
  }
  for(int i = 0; i < n; ++i)
  {
    for(int j = 0; j < n; ++j)
    {
      for(int k = 0; k < n; ++k)
      {
        if(y[i]==y[j]&&x[i]==x[k])
        {
          int square = std::abs((y[i]-y[k])*(x[i]-x[j]));
          ans = std::max(ans, square);
        }
      }
    }
  }
  std::cout << ans;
}
