#include <bits/stdc++.h>

struct Interval
{
  int start, end;
  Interval(int s, int e)
  {
    start = s;
    end = e;
  }
};

int main()
{
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out" , "w", stdout);
  int n,maximum = 0; std::cin >> n;
  std::vector<Interval> v;
  for(int i = 0; i < n; ++i)
  {
    int start, end; std::cin >> start >> end;
    v.push_back(Interval(start,end));
    maximum=std::max(maximum,end);
  }
  int ans = 0;
  for(int i = 0; i < n; ++i) // deleted lifeguard
  {
    int curr = 0;
    for(int time=1; time <= maximum; ++time) // linear search
    {
      for(int j = 0; j < n; ++j)
      {
        if(i!=j)
        {
          if(v[j].start<=time && v[j].end>time)
          {
            ++curr; break;
          }
        }
      }
    }
    ans = std::max(curr,ans);
  }
  std::cout << ans;
}
