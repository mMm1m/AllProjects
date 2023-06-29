#include <bits/stdc++.h>
using ll = long long;

std::vector<ll> prefix_function(std::string str)
{
  std::vector<ll> ans(str.size());
  for(ll i = 1, j=0 ;i < str.size(); i++)
  {
    while(j > 0 && str[i]!=str[j])
      j = ans[j-1];
    if (str[i] == str[j])
      j++;
    ans[i] = j;
  }
  return ans;
}

int main()
{
  std::string string, pattern;
  std::cin >> string >> pattern;
  std::string str = pattern+"#"+string;
  auto v = prefix_function(str);
  ll ans = 0;
  for(auto& a : v)
  {
    if(a==pattern.size())
      ans++;
  }
  std::cout << ans;
}
