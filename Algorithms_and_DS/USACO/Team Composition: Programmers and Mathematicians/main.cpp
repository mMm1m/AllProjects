#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int a,b;
    std::cin >> a >> b;
    int c = (a+b)/4, d = std::min(a,b);
    int ans = (c <= d) ? c : d ;
    std::cout << ans << '\n';
  }
}
