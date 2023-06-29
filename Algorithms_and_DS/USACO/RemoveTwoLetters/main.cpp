#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int n; std::cin >> n;
    std::string str; std::cin >> str;
    for(int i = 0;  i < str.size()-2; ++i)
      if(str[i]==str[i+2]) --n;
    std::cout << n-1 << '\n';
  }
}
