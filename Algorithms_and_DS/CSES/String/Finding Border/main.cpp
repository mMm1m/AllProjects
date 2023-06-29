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
  std::string str;
  std::cin >> str;
  auto v = prefix_function(str);
  ll j = v[str.size()-1];
  std::vector<ll> ans;
  while(j>0 )
  {
    ans.push_back(j);
    j = v[j-1];
  }
  std::sort(ans.begin(), ans.end());
  for(auto& a : ans)
    std::cout << a << " ";
}