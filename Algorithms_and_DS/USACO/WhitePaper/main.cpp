#include <bits/stdc++.h>

struct Rectangle
{
  int x1, y1, x2, y2;
  int area()
  {
    return (x2-x1)*(y2-y1);
  }
};

typedef std::pair<int, int> pii;

std::pair<pii, pii> intersection(pii a, pii b, pii c, pii d) {
  int lf, rg, up, dn;
  lf = std::max(std::min(a.first, b.first), std::min(c.first, d.first));
  rg = std::min(std::max(a.first, b.first), std::max(c.first, d.first));
  up = std::min(std::max(a.second, b.second), std::max(c.second, d.second));
  dn = std::max(std::min(a.second, b.second), std::min(c.second, d.second));

  if (rg <= lf || up <= dn) return { {0, 0}, {0, 0} };

  return { { lf, dn }, { rg, up } };
}

long long area(pii a, pii b) {
  return 1ll * abs(a.first - b.first) * abs(a.second - b.second);
}

int main() {

  Rectangle white_1, black_1, black_2;
  int w_x1, w_y1, w_x2, w_y2;
  std::cin >> w_x1 >> w_y1 >> w_x2 >> w_y2;
  white_1.x1  = w_x1; white_1.y1 = w_y1; white_1.x2 = w_x2; white_1.y2 = w_y2;
  int b_x1, b_y1, b_x2, b_y2;
  std::cin >> b_x1 >> b_y1 >> b_x2 >> b_y2;
  black_1.x1  = b_x1; black_1.y1 = b_y1; black_1.x2 = b_x2; black_1.y2 = b_y2;
  int b_x3, b_y3, b_x4, b_y4;
  std::cin >> b_x3 >> b_y3 >> b_x4 >> b_y4;
  black_2.x1  = b_x3; black_2.y1 = b_y3; black_2.x2 = b_x4; black_2.y2 = b_y4;

  std::pair<pii, pii> wb1 = intersection(std::make_pair(white_1.x1,white_1.y1), std::make_pair(white_1.x2,white_1.y2),
                     std::make_pair(black_1.x1,black_1.y1), std::make_pair(black_1.x2,black_1.y2));
  std::pair<pii, pii> wb2 = intersection(std::make_pair(white_1.x1,white_1.y1), std::make_pair(white_1.x2,white_1.y2),
                     std::make_pair(black_2.x1,black_2.y1), std::make_pair(black_2.x2,black_2.y2));
  std::pair<pii, pii> inter = intersection(wb1.first, wb1.second, wb2.first, wb2.second);

  long long swhite = area(std::make_pair(white_1.x1,white_1.y1), std::make_pair(white_1.x2,white_1.y2));
  long long swb1 = area(wb1.first, wb1.second);
  long long swb2 = area(wb2.first, wb2.second);
  long long sinter = area(inter.first, inter.second);

  if (swhite > swb1 + swb2 - sinter) std::cout << "YES\n";
  else std::cout << "NO\n";
}