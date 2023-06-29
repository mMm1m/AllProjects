#include <bits/stdc++.h>
using ll = long long;

int main() {
 // freopen("rental.in", "r", stdin);
  ll n, m, r;
  std::cin >> n >> m >> r;

  std::vector<ll> milk_amt(n);
  for (int i = 0; i < n; i++)
    std::cin >> milk_amt[i];

  std::vector<std::pair<ll, ll>> shops(m);
  for (int i = 0; i < m; i++)
    std::cin >> shops[i].second >> shops[i].first;

  std::vector<ll> rent(r);
  for (int i = 0; i < r; i++)
    std::cin >> rent[i];

  sort(milk_amt.begin(), milk_amt.end(), std::greater<ll>());
  sort(shops.begin(), shops.end(), std::greater<std::pair<ll, ll>>());
  sort(rent.begin(), rent.end(), std::greater<ll>());

  for(auto& a : milk_amt)
    std::cout << a << " ";
  std::cout << "\n";

  for(auto& a : shops)
    std::cout << a.first << " " << a.second << "     ";
  std::cout << "\n";

  for(auto& a : rent)
    std::cout << a << " ";
  std::cout << "\n";

  ll shop_at = 0, rent_at = 0, cow_at = 0, max_money = 0;
  while (cow_at < n) {
    ll amt = milk_amt[cow_at], for_selling = 0, curr_shop = shop_at, last = 0;

    while(shop_at < m)
    {
      for_selling += shops[curr_shop].first*std::min(shops[curr_shop].second, amt);
      amt -= std::min(shops[curr_shop].second, amt);

      if(amt == 0)
      {
        last = for_selling;
        break;
      }
      else curr_shop++;
    }

    // choose shop
    if(rent_at >= r || for_selling > rent[rent_at])
    {
      max_money += for_selling;
      shop_at = curr_shop;
      if(shop_at < m)
        shops[shop_at].second -= last;
      cow_at++;
    }
    // choose rent
    else
    {
      max_money += rent[rent_at];
      n--;
      rent_at++;
    }

  }

  std::cout << "\n";

 // freopen("rental.out", "w", stdout);

  std::cout << max_money << "\n";

}