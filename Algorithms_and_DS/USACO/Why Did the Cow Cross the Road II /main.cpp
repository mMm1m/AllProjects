#include <bits/stdc++.h>

int main()
{
  freopen("circlecross.in","r",stdin);
  freopen("circlecross.out","w",stdout);
  std::string str; std::cin >> str;
  std::map<char, std::pair<int,int>> map;
  for(int i = 0; i < 26; ++i)
  {
    map[(char)i+65] = std::make_pair(-1,-1);
  }
  for(int i = 0; i < str.size(); ++i)
  {
    if (map[str[i]].first == -1) map[str[i]].first = i;
    else map[str[i]].second = i;
  }
  int count = 0;
  for(auto& a : map)
  {
    for(auto& b : map)
    {
      count += (b.second.first>a.second.first && b.second.first<a.second.second
        && a.second.second<b.second.second);
    }
  }
  std::cout << count;
}
