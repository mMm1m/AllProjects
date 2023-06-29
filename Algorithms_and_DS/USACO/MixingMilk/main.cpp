#include <bits/stdc++.h>
using p = std::pair<int,int>;

void modify(int i,std::vector<p>& v)
{
  int amount = std::min(v[i].second, v[(i+1)%3].first-v[(i+1)%3].second);
  v[i].second -= amount;
  v[(i+1)%3].second += amount;
}

int main()
{
  freopen("mixmilk.in","r", stdin);
  freopen("mixmilk.out", "w", stdout);
  std::vector<p> v(3);
  for(int i = 0; i < 3; ++i)
    std::cin >> v[i].first >> v[i].second;
  for(int i = 0; i < 100; ++i)
    modify((i)%3,v);
  std::cout << v[0].second << '\n' << v[1].second << '\n' << v[2].second;
}
