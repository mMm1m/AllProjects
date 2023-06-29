#include <bits/stdc++.h>

int main()
{
  freopen("herding.in","r",stdin);
  freopen("herding.out","w",stdout);
  std::vector<int> v(3); for(auto& a : v) std::cin >> a;
  std::sort(v.begin(), v.end());
  int min,max;
  if(v[1]-v[0]==1 && v[2]-v[1]==1) min = 0;
  else if(v[2]-v[1]==2 || v[1]-v[0]==2) min = 1;
  else min = 2;
  max = std::max({v[2]-v[1],v[1]-v[0]})-1;
  std::cout << min << '\n' << max;
}
