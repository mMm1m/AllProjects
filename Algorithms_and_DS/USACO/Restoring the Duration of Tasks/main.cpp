#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    std::vector<std::pair<int,int>> p(n, {0,0});
    for(int i = 0; i < n;i++) {int a; std::cin >> a; p[i].first=a;}
    for(int i = 0; i < n;i++) {int a; std::cin >> a; p[i].second=a;}
    std::sort(p.begin(), p.end());
    std::cout << p[0].second-p[0].first << " ";
    for(int i = 1; i < n; i++)
    {
      if(p[i-1].second > p[i].first)
        p[i].first=p[i-1].second;
      std::cout << p[i].second-p[i].first << " ";
    }
    std::cout << '\n';
  }
}
