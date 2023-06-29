#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int l,r,k; std::cin >> l >> r >> k;
    int odd_num = (r-(l-1))-(r/2-(l-1)/2);
    if((l==r&&l>1&&r>1)||(odd_num<=k)) std::cout << "YES\n";
    else
    {
      std::cout << "NO\n";
    }
  }
}
