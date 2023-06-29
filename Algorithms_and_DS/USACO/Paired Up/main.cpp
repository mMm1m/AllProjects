#include <bits/stdc++.h>

int main()
{
  freopen("pairup.in","r",stdin);
  freopen("pairup.out","w",stdout);
  int n; std::cin >> n;
  std::vector<std::pair<int,int>> p;
  for(int i = 0; i < n; ++i)
  {
    int x,y; std::cin >> x >> y;
    p.push_back(std::make_pair(y,x));
  }
  std::sort(p.begin(),p.end());
  int left = 0, right = n-1, answer = 0;
  while(left <= right)
  {
    int min = std::min(p[left].second,p[right].second);
    if(left==right) min /= 2;
    answer = std::max(answer, p[left].first+p[right].first);
    p[left].second -= min;
    p[right].second -= min;
    if(p[left].second==0) ++left;
    if(p[right].second==0) --right;
  }
  std::cout << answer;
}
