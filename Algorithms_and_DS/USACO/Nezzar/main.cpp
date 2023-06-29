#include <bits/stdc++.h>
using ll = long long;

bool cmp(const ll& l1,const ll& l2)
{
  return l1 > l2;
}

void solution()
{
  int n;
  std::cin >> n;
  std::vector<ll> vector(2*n);
  for(int i = 0; i < 2*n; i++)
    std::cin >> vector[i];
  std::sort(vector.begin(), vector.end(), cmp);
  ll sum = 0;
  std::set<ll> set;
  for(int i = 1; i < 2*n; i+=2)
  {
    ll curr = (vector[i-1]-sum)/(2*n-(i-1));
    if(vector[i-1]!=vector[i] || (vector[i-1]-sum)%(2*n-(i-1))!=0
    || set.count(curr) || curr < 1)
    {
      std::cout << "NO" << "\n";
      return;
    }
    set.insert(curr);
    sum += 2*curr;
  }
  std::cout << "YES" << "\n";
}

int main()
{
  ll query;
  std::cin >> query;
  for(int i = 0; i < query; i++)
    solution();
}
