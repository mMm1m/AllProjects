#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    std::string str;
    std::cin >> str;
    std::sort(str.begin(), str.end());
    std::cout << str << '\n';
  }
}
