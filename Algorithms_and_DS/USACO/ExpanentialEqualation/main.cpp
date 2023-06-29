#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int n; std::cin >> n;
    if(n%2==0)
      std::cout << 1 << " " << n/2 << '\n';
    else
      std::cout << -1 << '\n';
  }
}
