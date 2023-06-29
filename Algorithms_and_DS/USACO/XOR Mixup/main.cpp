#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int n; std::cin >> n;
    std::vector<int> v(n); for(auto& a : v) std::cin >> a;
    if(n==2)
      std::cout << v[0] << '\n';
    else
    {
      std::swap(v[0],v[n-1]);
      int val_ = v[0];
      for(int j = 0; j < n-1; ++j)
        val_ ^= v[j];
      if(val_==v[n-1]) {std::cout << v[n-1] << '\n'; continue;}

      for(int i = 0; i < n-1; i++)
      {
      std::swap(v[i],v[n-1]);
      int val = v[0];
      for(int j = 0; j < n-1; ++j)
      {
        val ^= v[j];
        std::cout << val << " ";
      }
      std::cout << '\n';
      if(val==v[n-1]) {std::cout << v[n-1] << '\n'; break;}
      }
    }
  }
}
