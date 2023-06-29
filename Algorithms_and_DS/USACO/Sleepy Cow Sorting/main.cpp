#include <bits/stdc++.h>

int main()
{
  freopen("sleepy.in", "r", stdin);
  freopen("sleepy.out", "w",stdout);
  int n; std::cin >> n;
  std::vector<int> v(n); for(auto& a : v) std::cin >> a;
  int idx = n-1;
  while(idx >= 1)
  {
    if(v[idx-1]<v[idx]) --idx;
    else break;
  }
  std::cout << n-(n-idx);
}
