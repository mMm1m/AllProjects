#include <bits/stdc++.h>

struct Interval
{
  int start_, continue_;
  Interval(int s, int c)
  {
    start_ = s;
    continue_ = c;
  }
};

int main()
{
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out","w",stdout);
  int n; std::cin >> n;
  std::vector<Interval> v;
  for(int i = 0; i < n; ++i)
  {
    int s,c; std::cin >> s >> c;
    v.push_back(Interval(s,c));
  }
  std::sort(v.begin(),v.end(), [](const Interval& i1, const Interval& i2){
    return i1.start_ < i2.start_;
  });
  if(n==1) std::cout << v[0].start_+v[0].continue_;
  else
  {
    int tmp = v[0].start_+v[0].continue_;
    for(int i = 1; i < n; ++i)
    {
      if(v[i].start_<tmp) {
        v[i].start_=tmp;
        tmp = v[i].start_+v[i].continue_;
      }
      else tmp = v[i].start_+v[i].continue_;
    }
    std::cout << tmp;
  }
}
