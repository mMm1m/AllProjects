#include <bits/stdc++.h>

int main()
{
  int n,q; std::cin >> n >> q;
  std::vector<int> v(n), prefix(n+1,0);
  for(auto& a : v) std::cin >> a;
  for(int i = 0; i < n; ++i) prefix[i+1]=prefix[i]+v[i];

  for(int i = 0; i < q; ++i)
  {
    int start, end; std::cin >> start >> end;
    std::cout << prefix[end]-prefix[start] << '\n';
  }
}
