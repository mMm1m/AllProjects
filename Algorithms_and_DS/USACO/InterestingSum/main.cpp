#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    std::vector<int > v(n);
    for(auto& a : v)
      std::cin >> a;
    std::sort(v.begin(), v.end());
    std::cout << v[n-1]+v[n-2]-v[0]-v[1] << '\n';
  }
}
