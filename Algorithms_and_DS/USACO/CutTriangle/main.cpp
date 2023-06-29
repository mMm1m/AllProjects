#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--) {
    std::vector< std::pair< int, int>> p(3);
    std::set<int> x,y;
    for (auto& a: p)
    {
      std::cin >> a.first >> a.second;
      x.insert(a.first); y.insert(a.second);
    }
    if((x.size()==3 && y.size()==0) || (y.size()==3 && x.size()==0) || (x.size()==2 && y.size()==2))
    {
      std::cout << "NO" << '\n';
      continue;
    }
    std::cout << "YES" << '\n';
  }
}
