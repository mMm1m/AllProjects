#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    std::vector<int> v(n), two;
    for(int i = 0; i < n; i++) {
      std::cin >> v[i];
      if(v[i]==2) two.push_back(i);
    }
    if(two.size()==0)
    {
      std::cout << 1 << '\n';
      continue;
    }
    if(two.size()%2==0) {
      std::cout << ++two[two.size()/2-1] << '\n';
      continue;
    }
    std::cout << -1 << '\n';
  }
}
