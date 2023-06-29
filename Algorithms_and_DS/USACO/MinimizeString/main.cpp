#include <bits/stdc++.h>

int main()
{
  int tests;
  std::cin >> tests;
  while(tests--)
  {
    int n,m,k;
    std::cin >> n >> m >> k;
    std::vector<char> up(n), low(m);
    for(auto& a : up) std::cin >> a; for(auto& a : low) std::cin >> a;
    std::sort(up.begin(), up.end(), std::greater<char>()); std::sort(low.begin(), low.end(), std::greater<char>());
    int p1 = 0, p2 = 0;
    std::string answer;
    while(!up.empty() && !low.empty())
    {
      bool cmp = up.back() < low.back();
      if(cmp && p2==k) cmp = 0;
      if(!cmp && p1==k) cmp = 1;
      if(cmp)
      {
        answer += up.back();
        p2++; p1=0;
        up.pop_back();
      }
      else
      {
        answer += low.back();
        p1++; p2 = 0;
        low.pop_back();
      }
    }
    std::cout << answer << '\n';
  }
}
