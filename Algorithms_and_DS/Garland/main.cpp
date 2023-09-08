#include <bits/stdc++.h>

const double EPS = 0.000001;
double solution(int n,double& b, double left, double right)
{
  std::vector<double> v(n);
  v[0] = left;
  v[1] = right;
  double min = left;
  for(int i = 2; i < n; ++i)
  {
    v[i] = 2*v[i-1]+2-v[i-2];
    min = std::min(min, v[i]);
  }
  b = v[n-1];
  return min;
}

int main()
{
  int n; double a, b = 0; std::cin >> n >> a;
  double left = 0, right = a;
  while(right-left > EPS)
  {
    double mid = right + (left-right)/2;
    if(solution(n,b,a,mid) < 0) {left = mid;}
    else {right = mid;}
  }
 std::cout << std::fixed << std::setprecision(2) << b;
}
