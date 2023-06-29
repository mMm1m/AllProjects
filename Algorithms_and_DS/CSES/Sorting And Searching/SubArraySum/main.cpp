#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll n,x;
  std::cin >> n >> x;
  std::vector<ll> v(n);
  for(auto& a : v)
    std::cin >> a;
  ll left = 0, right = 0, count = 0, sum = v[0];
  while(right < n)
  {
    if(sum < x)
    {
      if(sum==x)
        ++count;
      ++right;
      sum += v[right];
    }
    else
    {
      if(sum==x)
        ++count;
      sum -= v[left];
      ++left;
    }
  }
  std::cout << count;
}




#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll n,x;
  std::cin >> n >> x;
  std::map<ll , ll> map;
  ll prefix_sum = 0;
  std::vector<ll> vector(n);
  for(auto& a : vector)
    std::cin >> a;

  ll answer = 0;
  map[0] = 1;
  for(int i = 0; i < n; i++)
  {
    prefix_sum += vector[i];
    answer += map[prefix_sum-x];
    map[prefix_sum]++;
  }
  std::cout << answer;
}