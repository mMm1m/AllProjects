#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    std::string str; std::cin >> str;
    std::map<char,int> map; map['L']=0; map['R']=0;
    for(int i = 0; i < n; i++)
      ++map[str[i]];
    bool all_eq = false;
    for(auto& a : map)
      if(a.second==0) all_eq=true;
    int index = 0;
    if(all_eq) {std::cout << -1 << '\n'; continue;}
    else
    {
      for(int i = 1; i < str.size(); i++)
        if(str[i-1]=='L' && str[i]=='R') {std::swap(str[i], str[i-1]); index = i; break;}
    }
    std::cout << index << '\n';
  }
}
