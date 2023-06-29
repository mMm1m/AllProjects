#include <bits/stdc++.h>

std::set<std::string> inter(std::set<std::string> s1,
                            std::set<std::string> s2)
{
  std::set<std::string> result;
  for(auto& a : s1)
  {
    if(s2.count(a))
      result.insert(a);
  }
  return result;
}

int main()
{
  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);
  int n;
  std::cin >> n;
  std::vector<std::set<std::string>> set_(n);
  for(int i = 0; i < n; i++)
  {
    std::string animal_name;
    int amount;
    std::cin >> animal_name >> amount;
    for(int j = 0; j < amount; j++)
    {
      std::string string;
      std::cin >> string;
      set_[i].insert(string);
    }
  }

  int maximum = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = i+1; j < n; j++)
    {
      std::set<std::string> intersection = inter(set_[i], set_[j]);
      maximum = std::max(maximum, static_cast<int>(intersection.size()+1));
    }
  }
  std::cout << maximum;
}
