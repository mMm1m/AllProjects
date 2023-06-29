#include <bits/stdc++.h>

int main()
{
  std::string str;
  std::cin >> str;
  for(int i = 0; i < str.size(); i++)
  {
    if(str[i]=='H' || str[i]== 'Q' || str[i]== '9')
    {
      std::cout << "YES";
      return 0;
    }
  }
  std::cout << "NO";
  return 0;
}
