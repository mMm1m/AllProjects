#include <bits/stdc++.h>

struct Rectangle
{
  int x1, x2, y1, y2;
};

int main()
{
  freopen("square.in", "r", stdin);
  freopen("square.out", "w", stdout);
  Rectangle orig, end;
  std::cin >> orig.x1 >> orig.y1 >> orig.x2 >> orig.y2;
  std::cin >> end.x1 >> end.y1 >> end.x2 >> end.y2;
  int maximum_y = std::max({orig.y1, orig.y2, end.y1, end.y2});
  int minimum_y = std::min({orig.y1, orig.y2, end.y1, end.y2});
  int maximum_x = std::max({orig.x1, orig.x2, end.x1, end.x2});
  int minimum_x = std::min({orig.x1, orig.x2, end.x1, end.x2});
  int max = std::max(std::abs(maximum_y-minimum_y), std::abs(maximum_x-minimum_x));
  std::cout << std::pow(max,2);
}
