#include <bits/stdc++.h>

int main()
{
  int n; std::cin >> n;
  std::vector<int> v(n), ans(n);
  for(auto& a : v) std::cin >> a;
  ans[0]=v[0]-1;
  for(int i = 1; i < n; ++i)
  {
    if(v[i]-(i+1)<=ans[i-1])
      ans[i]=ans[i-1]+1;
    else
      ans[i] = v[i]-(i+1);
  }
  for(auto& a : ans)
    std::cout << a << '\n';
}
