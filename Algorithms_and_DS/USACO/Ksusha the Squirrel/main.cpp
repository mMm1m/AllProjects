#include <bits/stdc++.h>

int main()
{
  int n,k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  int count = 0, max= 0;
  for(int i = 0; i < str.size(); i++)
  {
    if(str[i]=='.') count = 0;
    else ++count;
    max = std::max(max,count);
  }
  if(max >= k) std::cout << "NO";
  else std::cout << "YES";
}
