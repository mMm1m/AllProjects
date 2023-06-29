#include <bits/stdc++.h>

int main()
{
  //freopen("notlast.in","r",stdin);
  //freopen("notlast.out","w",stdout);
  std::map<std::string,int> map;
  int n; std::cin >> n;
  for(int i = 0; i < n; ++i)
  {
    std::string str; int val;
    std::cin >> str >> val;
    if(map.count(str)) map[str]+=val;
    else map[str]=val;
  }
  std::vector<int> v(1000,0);
  for(auto& a : map) ++v[a.second];
  // index value
  std::pair<int,int> f = {0,0}, s={0,0};
  for(int i = 0; i < 1000; ++i)
  {
    if(v[i]>0 && f.first==0 && f.second==0) {f.first=i; f.second=v[i];}
    else if(v[i]>0 && f.first!=0 && f.second!=0) {s.first=i; s.second=v[i]; break;}
  }
  for(auto& a : v) {std::cout << a << " ";} std::cout << '\n';
  std::cout << f.first << " " << f.second << " " << s.first << " " << s.second;
  if(s.second==1)
  {
    for(auto& a : map)
      if(a.second==s.first) {std::cout << a.first; break;}
  }
  else std::cout << "Tie";
}
