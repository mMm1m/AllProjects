#include <bits/stdc++.h>

int main()
{
  int n,t;
  std::cin >> t >> n;
  std::map<std::string, std::vector<std::string>> map;
  while(n--)
  {
    std::string string, temp;
    std::cin >> string;
    temp = string;
    std::sort(temp.begin(), temp.end());
    map[temp].push_back(string);
  }
  std::string str;
  while(getline(std::cin, str), str != "END")
  {
    std::cout << "Anagrams for: " << str << '\n';
    std::string temp = str;
    std::sort(str.begin(), str.end());
    auto it = map.find(str);
    if(it != map.end())
    {
      int count = 0;
      for(int i = 0; i < map[str].size(); i++)
      {
        std::cout << ++count << ") " << map[str][i] << '\n';
      }
    }
    else
    {
      std::cout << "No anagrams for: " << temp << '\n';
    }
  }
}
