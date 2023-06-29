#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n,coin;
    std::cin >> n >> coin;
    std::map<int,int> map;
    for(int i = 0; i < n; i++)
    {
      int a;
      std::cin >> a;
      ++map[a];
    }
    int coin_ = 0;
    for(auto& a : map)
    {
      int minimum = std::min(a.second, coin);
      coin_ += minimum;
    }
    std::cout << coin_  << '\n';
  }
}
