#include <bits/stdc++.h>

int main()
{
  int n, temp; std::cin >> n;
  std::set<int> set;
  for(int i = 1; i <= 2*n; ++i) set.insert(i);
  for(int i = 0; i < n; ++i)
  {
    std::cin >> temp;
    auto it = set.lower_bound(temp);
    if(*it <= n)
    {
      auto cont_it = set.lower_bound(temp+n);
      set.erase(cont_it);
      std::cout << *it << '\n';
    }
    else
    {
      auto cont_it = set.lower_bound(temp-n);
      set.erase(cont_it);
      std::cout << (*it)%n << '\n';
    }
    set.erase(it);
  }
}
