#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    // string and #_boy
    std::vector<std::pair<std::string, int> > v;
    // string and amount
    std::map<std::string,int> map;
    std::vector<int> k(3);
    for(int i = 0; i < 3; i++)
    {
      for(int j=  0; j < n; j++)
      {
        std::string str;
        std::cin >> str;
        v.push_back(std::make_pair(str,i+1));
        ++map[str];
      }
    }
    for(int i = 0; i < v.size(); i++)
    {
      if(map[v[i].first]==1) k[v[i].second-1]+=3;
      else if(map[v[i].first]==2) ++k[v[i].second-1];
    }
    for(auto& a : k)
      std::cout << a << " ";
    std::cout << '\n';
  }
}
