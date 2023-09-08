#include <bits/stdc++.h>

int k;
struct Jewel
{
  int v, w, index;
  Jewel(int v_, int w_, int idx)
  {
    v = v_;
    w = w_;
    index = idx;
  }
};
std::vector<Jewel> jewel;
// некоторый коэффициент v/w
double x;

bool cmp(const Jewel& j1, const Jewel& j2)
{
  return (j1.v-j1.w*(x)) > (j2.v-j2.w*(x));
}

bool check()
{
  std::sort(jewel.begin(), jewel.end(), cmp);
  double sum  = 0;
  for(int i = 0; i < k; ++i)
  {
    sum += jewel[i].v-jewel[i].w*x;
  }
  return sum >= 0;
}

int main()
{
  int n, a, b; std::cin >> n >> k;
  for(int i = 0; i < n; ++i)
  {
    std::cin >> a >> b;
    jewel.push_back(Jewel(a,b,i+1));
  }
  double l = 0, r = 1e9;
  const double EPS = 1e-6;
  while(r-l > EPS)
  {
    double mid = (double)l + (r-l)/2.0;
    x = mid;
    if(check()) {l = mid;}
    else {r = mid;}
  }
  x = l;
  std::sort(jewel.begin(), jewel.end(), cmp);
  for(int i = 0; i < k; ++i)
    std::cout << jewel[i].index << '\n';
}
