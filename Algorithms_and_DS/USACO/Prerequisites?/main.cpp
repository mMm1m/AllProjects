#include <bits/stdc++.h>

int main()
{
  int k,m;
  while(std::cin >> k, k > 0)
  {
    std::map<std::string, int> map;
    std::cin >> m;
    for(int i = 0; i < k; i++)
    {
      std::string value;
      std::cin >> value;
      ++map[value];
    }

    bool val = true;
    for(int i = 0; i < m; i++)
    {
      int c,r;
      std::cin >> c >> r;
      for(int j = 0; j < c; j++)
      {
        std::string str;
        std::cin >> str;
        if(map.find(str) != map.end()) --r;
      }
      if(r > 0)
      {
        val = false;
      }
    }
    if(!val)
    {
      std::cout << "no\n";
    }
    else
    {
      std::cout << "yes\n";
    }
  }
}
