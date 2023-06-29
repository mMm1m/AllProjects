#include <bits/stdc++.h>

int main()
{
  int m,n;
  while(scanf("%d%d", &m, &n), m != 0, n != 0)
  {
    std::cout << (((m + 1)/2) * ((n + 1)/2)) + (((m)/2) * ((n)/2)) << '\n';
  }
}
