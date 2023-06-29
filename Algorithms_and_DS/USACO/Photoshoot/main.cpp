#include <bits/stdc++.h>

int main()
{
  int n, rev = 0; std::cin >> n;
  std::string str; std::cin >> str;
  for(int i = n-2; i >= 0; i-=2)
  {
    if(str[i]==str[i+1]) continue;
    else if(str.substr(i,2)=="HG" && rev%2==1) ++rev;
    else if(str.substr(i,2)=="GH" && rev%2==0) ++rev;
  }
  std::cout << rev;
}