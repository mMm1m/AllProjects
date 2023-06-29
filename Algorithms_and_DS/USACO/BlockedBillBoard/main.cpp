#include <bits/stdc++.h>

struct Rectangle
{
  int x1, y1, x2, y2;
  Rectangle(int _x1, int _y1, int _x2, int _y2)
  {
    x1 = _x1;
    y1 = _y1;
    x2 = _x2;
    y2 = _y2;
  }
};

int area(const Rectangle& r)
{
  return (r.x1-r.x2)*(r.y1-r.y2);
}

int intersection(const Rectangle& r, const Rectangle& banner)
{
  int x = std::max(0,std::min(r.x2,banner.x2)-std::max(r.x1,banner.x1)), y = std::max(0,std::min(r.y2,banner.y2)-std::max(r.y1,banner.y1));
  return x*y;
}

int main()
{
  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);
  int x1_1, y1_1, x2_1, y2_1, x1_2, y1_2, x2_2, y2_2, x1_banner, y1_banner, x2_banner, y2_banner;
  std::cin >> x1_1 >> y1_1 >> x2_1 >> y2_1 >> x1_2 >> y1_2 >> x2_2 >> y2_2 >> x1_banner >> y1_banner >> x2_banner >> y2_banner;
  Rectangle r1(x1_1, y1_1, x2_1, y2_1), r2(x1_2, y1_2, x2_2, y2_2), banner(x1_banner, y1_banner, x2_banner, y2_banner);
  int ans = (area(r1)+ area(r2))-(intersection(r1,banner)+ intersection(r2,banner));
  std::cout << ans;
}