#include "bits/stdc++.h"
using ll = long long;
std::vector<ll> capacity(3), current_value(3);

void fill(int for_capacity, int milk)
{
  ll minimum = std::min(current_value[for_capacity],capacity[milk]-current_value[milk]);
  current_value[for_capacity] -= minimum;
  current_value[milk] += minimum;
}

int main()
{
  //freopen("mixmilk.in", "r", stdin);
  //freopen("mixmilk.out", "w", stdout);

  for(int i = 0; i < 3; i++)
  {
    ll a, b;
    std::cin >> a >> b;
    capacity[i] = a; current_value[i] = b;
  }

  for(int i = 0; i < 100; i++)
    fill((i)%3, (i+1)%3);
  for(int i = 0; i < 3; i++)
    std::cout << current_value[i] << "\n";
}