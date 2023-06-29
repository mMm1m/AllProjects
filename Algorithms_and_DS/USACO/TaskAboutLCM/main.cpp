#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int l,r; std::cin >> l >> r;
    if(2*l > r) std::cout << -1 << " " << -1 << '\n';
    else
      std::cout << l << " " << 2*l << '\n';
  }
}
