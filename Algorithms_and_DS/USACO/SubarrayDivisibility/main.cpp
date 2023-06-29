#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll n;
  std::cin >> n;
  std::vector<ll> vector(n,0);
  vector[0] = 1;
  ll prefix_sum = 0;
  for(int i = 0; i < n; i++)
  {
    ll value;
    std::cin >> value;
    prefix_sum += value;
    vector[((prefix_sum%n)+n)%n]++;
  }

  ll answer = 0;
  for(auto& a : vector)
    answer += a*(a-1)/2;
  std::cout << answer;
}
