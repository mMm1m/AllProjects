#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  for(int i = 0; i < t; i++)
  {
    int W,H,x1,y1,x2,y2, w2,h2;
    std::cin >> W >> H;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cin >> w2 >> h2;

    int w1 = x2 - x1;
    int h1 = y2 - y1;

    // place where find coordinate
    int top = H-h2;
    int bottom = h2;
    int left = w2;
    int right = W - w2;

    int need_top = std::max(0, y2 - top);
    int need_bottom = std::max(0, bottom - y1);
    int need_left = std::max(0, left - x1);
    int need_right = std::max(0, x2 - right);

    if(w1+w2>W)
    {
      need_left = 1e9;
      need_right = 1e9;
    }

    if(h1+h2>H)
    {
      need_top = 1e9;
      need_bottom = 1e9;
    }

    int answer = std::min({need_top, need_bottom, need_left, need_right});
    std::cout << ((answer == 1e9) ? -1 : answer) << "\n";
  }
}
