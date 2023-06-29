#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  std::vector<int> v;
  while(t--)
  {
    int n,k;
    std::cin >> n >> k;
    v.clear();
    for(int i = 0; i < n; i++) { int a; std::cin >> a; v.push_back(a); }
    std::sort(v.begin(), v.end());
    if(k%(v[n-1]+v[n-2])==0) {std::cout << 2*(k/(v[n-1]+v[n-2])) << '\n';}
    else if(k%(v[n-1]+v[n-2])<=v[n-1]) {std::cout << 2*(k/(v[n-1]+v[n-2])) + 1 << '\n';}
    else {std::cout << 2*(k/(v[n-1]+v[n-2]) + 2) << '\n';}
  }
}
