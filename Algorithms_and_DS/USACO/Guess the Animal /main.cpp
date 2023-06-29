#include <bits/stdc++.h>

std::set<std::string> two_sets(std::set<std::string>& s1, std::set<std::string>& s2)
{
  std::set<std::string> set;
  for(auto it = s1.begin(); it != s1.end(); ++it)
  {
    if(s2.count(*it))
      set.insert(*it);
  }
  return set;
}

int main()
{
  //freopen("guess.in", "r", stdin);
  //freopen("guess.out", "w", stdout);
  int n; std::cin >> n;
  std::vector<std::set<std::string>> v;
  for(int i = 0;i < n; ++i)
  {
    std::cin >> n; std::cin >> n;
    std::set<std::string> set;
    for(int j = 0; i < n; ++j)
    {
      std::string str; std::cin >> str;
      set.insert(str);
    }
    v.push_back(set);
  }
  int ans = 0;
  for(int i = 0; i < n; ++i)
  {
    for(int j = i+1; j < n; ++j)
    {
      auto set = two_sets(v[i],v[j]);
      for(auto& a : set)
        std::cout << a << " ";
      std::cout << '\n';
      ans = std::max(ans,(int)set.size()+1);
    }
  }
  std::cout << ans;
}
