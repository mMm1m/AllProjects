#include <bits/stdc++.h>

const int max_cows = 1000;

struct Bucket
{
  int start, end, buckets;
  Bucket(int s, int e, int b)
  {
    start = s;
    end = e;
    buckets = b;
  }
};

int main()
{
  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);
  int n,max = 0;; std::cin >> n;
  std::vector<Bucket> v;
  for(int i = 0; i < n; ++i)
  {
    int a,b,c; std::cin >> a >> b >> c;
    v.push_back(Bucket(a,b,c));
    max = std::max(std::max(a,b),max);
  }
  std::vector<int> vector(max+1), vector_r(max+2);
  for(auto& a : v)
  {
    vector[a.start]+=a.buckets;
    vector[a.end]-=a.buckets;
  }
  for(int i = 0; i < max+1; i++)
    vector_r[i+1] = vector_r[i]+vector[i];
  int maximum= 0;
  for(auto& a : vector_r)
    maximum = std::max(maximum, a);
  std::cout << maximum;
}