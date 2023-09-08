#include <bits/stdc++.h>
#define fs(x) std::fixed << std::setprecision(10) << x;
const double EPS = 1e-10;

double cnt(double x)
{
  return (x*x) + std::sqrt(x);
}

int main()
{
  double c; std::cin >> c;
  double l = 0, r = 1e5;
  while(r-l > EPS)
  {
    double mid = l + (r-l)/2;
    if(cnt(mid) > c) {r = mid;}
    else l = mid;
  }
  std::cout << std::fixed << std::setprecision(6) << l ;
}
