#include <bits/stdc++.h>

int main()
{
  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);
  int x,y; std::cin >> x >> y;
  if(x==y) std::cout << 0 << '\n';
  else if(x < y)
  {
    if(y-x==1) {std::cout << 1; return 0;}
    int curr_coordinate = x+1, step = 1, ans = 1;
    while(true)
    {
      ans += std::abs(step*(-2)-step);
      step = step*(-2);
      curr_coordinate = x + step;
      if(curr_coordinate>=y)
        break;
    }
    ans -= (curr_coordinate-y);
    std::cout << ans;
  }
  else
  {
    int curr_coordinate = x+1, step = 1, ans = 1;
    while(true)
    {
      ans += std::abs(step*(-2)-step);
      step = step*(-2);
      curr_coordinate = x + step;
      if(curr_coordinate<=y)
        break;
    }
    ans -= (y-curr_coordinate);
    std::cout << ans;
  }
}
