#include <bits/stdc++.h>

double sum(const std::vector<int>& v, int start, int end)
{
  double sum_ = 0;
  for(int i = start; i <= end; ++i)
    sum_ += v[i];
  return sum_;
}

int main()
{

  int n;
  std::cin >> n;
  std::vector< int > v(n);
  for (auto& a: v) std::cin >> a;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      double sum_ = sum(v,i,j);
      sum_ /=  (j - i + 1);
      for (int k = i; k <= j; ++k)
      {
        if(v[k]==sum_) {++count; break;}
      }
    }
  }
  std::cout << count;
}
