#include <bits/stdc++.h>
int main()
{
  char arr[3] = {'F', 'M', 'S'};
  std::vector<std::pair<std::string, char>> v(3);
  std::map<std::string, int> map;
  for(int i = 0; i < 3; i++)
  {
    std::string a;
    std::cin >> a;
    v[i].first = a; v[i].second = arr[i];
    map[a]++;
  }

  if(map.size()==3 || map.size()==1)
  {
    std::cout << "?";
    return 0;
  }

  else
  {
    if((map["paper"]==1 && map["scissors"]==2) || (map["rock"]==1 && map["paper"]==2)
    || (map["scissors"]==1 && map["rock"]==2))
    {
      std::cout << "?";
      return 0;
    }
    else
    {
      if(map["paper"]==1)
      {
        for(int i = 0;  i< 3; i++)
        {
          if(v[i].first=="paper")
            std::cout << v[i].second;
        }
      }
      if(map["scissors"]==1)
      {
        for(int i = 0;  i< 3; i++)
        {
          if(v[i].first=="scissors")
            std::cout << v[i].second;
        }
      }
      if(map["rock"]==1)
      {
        for(int i = 0;  i< 3; i++)
        {
          if(v[i].first=="rock")
            std::cout << v[i].second;
        }
      }
    }
  }
}
