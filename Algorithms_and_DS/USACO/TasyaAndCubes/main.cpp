#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int n,s,r; std::cin >> n >> s >> r;
    std::cout << s-r << " ";
    int k = r%(n-1),l = r/(n-1);
    std::vector<int> v;
    for(int i = 1; i <= n-1; ++i)
      v.push_back(l);
    for(int i = 1; i<=k; ++i)
      ++v[i-1];
    for(auto& a : v)
      std::cout << a << " ";
    std::cout << '\n';
  }
}
