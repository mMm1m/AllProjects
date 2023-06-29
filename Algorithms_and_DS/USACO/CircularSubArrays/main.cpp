#include <bits/stdc++.h>
int main()
{
  int n,k;
  std::cin >> n >> k;
  std::vector<int> v(n);
  for(auto&a : v)
  {
    std::cin >> a;
  }
  std::vector<int> s;
  int sum = 0;
  for(int i = 0; i < n; i+=k)
  {
    for(int j = 0; j < k; j++)
    {
      sum += v[i+j];
    }
    s.push_back(sum);
    sum = 0;
  }
  int med = s[s.size()/2], ans = 0;
  for(int i = 0; i < s.size(); i++)
    ans += std::abs(s[i]-med);
  std::cout << ans;
}