#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int n; std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
      int val; std::cin >> val;
      (val%2==0) ? v[i]=1 : v[i]=0;
    }
    int cnt = 0;
    for(int i = 1; i< n; ++i)
    {
      if(v[i]==v[i-1]) ++cnt;
    }
    std::cout << cnt << '\n';
  }
}
