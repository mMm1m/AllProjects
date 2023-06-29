#include <bits/stdc++.h>
using ll = long long;

int main()
{
  ll n,x;
  std::cin >> n >> x;
  std::pair<ll,ll> best[1<<n];
  std::vector<ll> weight(n);
  for(auto& a : weight)
    std::cin >> a;
  for (int s = 1; s < (1<<n); s++) {
    // начальное значение: необходимо n+1 поездок
    best[s] = {n+1,0};
    for (int p = 0; p < n; p++) {
      if (s&(1<<p)) {
        auto option = best[s^(1<<p)];
        if (option.second+weight[p] <= x) {
          // добавить p в существующую группу пассажиров
          option.second += weight[p];
        } else {
          // предусмотреть для p отдельную поездку
          option.first++;
          option.second = weight[p];
        }
        best[s] = min(best[s], option);
      }
    }
  }
  std::cout << best[(1<<n)-1].first+1;
}