#include <bits/stdc++.h>
using ll = long long;

int main()
{
  freopen("highcard.in", "r", stdin);
  freopen("highcard.out", "w", stdout);
  ll n;
  std::cin >> n;
  std::vector<ll> vector(n);
  std::set<ll> set;
  for(int i = 0; i < n; i++)
  {
    std::cin >> vector[i];
    set.insert(vector[i]);
  }

  std::vector<ll> Bessy;
  for(int i = 1; i <= 2*n; i++)
  {
    auto it = set.find(i);
    if(it==set.end()) Bessy.push_back(i);
  }
  std::sort(vector.begin(), vector.end());

  ll vector_pointer = 0, Bessy_pointer = 0, ans = 0;
  while(vector_pointer < n && Bessy_pointer < n)
  {
    if(Bessy[Bessy_pointer] > vector[vector_pointer])
    {
      ans++;
      Bessy_pointer++;
      vector_pointer++;
    }
    else
      Bessy_pointer++;
  }
  std::cout << ans;
 }
