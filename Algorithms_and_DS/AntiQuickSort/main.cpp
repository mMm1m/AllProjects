#include <bits/stdc++.h>

void anti_fast(std::vector<int>& v, int n)
{
  for(int i = 0; i < n; ++i)
  {
    std::swap(v[i], v[i/2]);
  }
}

int pivot(std::vector<int>& v, int l, int r)
{
  int tmp = v[l+(r-l)/2];
  int i = l, j = r;
  while(i <= j)
  {
    while(v[i] < tmp) ++i;
    while(v[j] > tmp) --j;
    if(i >= j) break;
    std::swap(v[i++], v[j--]);
  }
  return j;
}

void qsort(std::vector<int>& v, int l, int r)
{
  if(l < r)
  {
    int piv = pivot(v, l, r);
    qsort(v, l, piv);
    qsort(v, piv+1, r);
  }
}

int main()
{
  int n; std::cin >> n;
  std::vector<int> v(n);
  std::iota(v.begin(), v.end(), 1);
  anti_fast(v,n);
  for(auto& a : v) std::cout << a << " "; std::cout << '\n';
  qsort(v,0,n-1);
  for(auto& a : v) std::cout << a << " ";
}
