#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll t;
  std::cin >> t;
  while(t--)
  {
    double x1,y1,x2,y2,x3,y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double kstart = (y2-y1)*(x3-x2), kend = (y3-y2)*(x2-x1);
    if(kend > kstart)
    {
      std::cout << "LEFT" << '\n';
    }
    else if(kend < kstart)
    {
      std::cout << "RIGHT" << '\n';
    }
    else
      std::cout << "TOUCH" << '\n';
  }
}
