#include <bits/stdc++.h>
#include <fstream>
struct Line
{
  int start, end;
  Line(int s, int e)
  {
    start = s;
    end = e;
  }
};

int intersection(const Line& l1, const Line& l2)
{
  return std::max(std::min(l1.end, l2.end)-std::max(l1.start, l2.start),0);
}

int main()
{
  freopen("paint.in","r",stdin);
  freopen("paint.out", "w", stdout);
  int a,b,c,d; std::cin >> a >> b >> c >> d;
  Line l1(a,b), l2(c,d);
  int ans = (b-a)+(d-c); ans -= intersection(l1,l2);
  std::cout << ans;
}
