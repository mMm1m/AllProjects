#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll t;
  std::cin >> t;
  while(t--)
  {
    ll n;
    std::cin >> n;
    ll max = -1, answer = 0;
    for(int i = 0; i < n; i++)
    {
      ll a, b;
      std::cin >> a >> b;
      ll max_ = std::max(a,b), min_ = std::min(a,b);
      max= std::max(max, max_);
      answer += min_;
    }
    answer += max; answer *= 2;
    std::cout << answer << '\n';
  }
}
