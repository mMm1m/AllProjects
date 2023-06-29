#include <bits/stdc++.h>

int main()
{
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);
  int x,y,m, max = 0; std::cin >> x >> y >> m;
  for(int i = 0; i < m; ++i)
  {
    if(i*x > m) break;
    int curr = i*x;
    for(int j = 0; j < m; ++j)
    {
      if((curr+j*y)>m) break;
      curr += j*y;
      max = std::max(max, curr);
    }
  }
  std::cout << max;
}
