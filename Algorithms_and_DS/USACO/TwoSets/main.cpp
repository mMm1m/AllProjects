#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll n;
  std::cin >> n;
  ll sum = n*(n-1)/2;
  if(n%2==0)
  {
    std::cout << "YES";
  }
  else
  {
    ll target = sum/2, t = n;
    std::set<ll> set1, set2;
    while(set1.count(target)==0)
    {
      target -= t;
      set2.insert(t);
      set1.erase(t);
      --t;
    }
    set1.erase(target);
    set2.insert(target);
    std::cout << set1.size() << '\n';
    for(auto& a : set1)
      std::cout << a << " ";
    std::cout << '\n';
    for(auto& a : set2)
      std::cout << a << " ";
    std::cout << '\n';
  }
}
