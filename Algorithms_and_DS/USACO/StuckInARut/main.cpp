#include <bits/stdc++.h>
using ll = long long;

struct Cow
{
  ll x,y, index;
  Cow(ll x_, ll y_, ll idx)
  {
    x = x_;
    y = y_;
    index = idx;
  }
};

int main()
{
  std::vector<Cow> north, east, cow;
  std::vector<char> symbols;
  ll n; std::cin >> n;
  for(ll i = 0; i < n; ++i)
  {
    char c; ll x,y; std::cin >> c >> x >> y;
    if(c=='N') north.push_back(Cow(x,y,i));
    if(c=='E') east.push_back(Cow(x,y,i));
    cow.push_back(Cow(x,y,i));
    symbols.push_back(c);
  }

  sort(north.begin(), north.end(),[](const Cow &c1, const Cow &c2){
    return c1.x < c2.x; });
  sort(east.begin(), east.end(),[](const Cow &c1, const Cow &c2){
    return c1.y < c2.y; });
  std::vector<ll> stop_pos(n, -1);
  for (const Cow &ncow : north) {
    for (const Cow &ecow : east) {
      if (ncow.x > ecow.x && ncow.y < ecow.y) {
        int n_trav = ecow.y - ncow.y;
        int e_trav = ncow.x - ecow.x;
        if (n_trav < e_trav && stop_pos[ecow.index] == -1) {
          stop_pos[ecow.index] = ncow.x;
        }
        if (n_trav > e_trav && stop_pos[ecow.index] == -1) {
          stop_pos[ncow.index] = ecow.y;
          break;
        }
      }
    }
  }

  for(int i = 0; i < n; ++i)
  {
    if(stop_pos[i]==-1) std::cout << "Infinity" << '\n';
    else if(symbols[i]=='N') std::cout << std::abs(cow[i].y-stop_pos[i]) << '\n';
    else if(symbols[i]=='E') std::cout << std::abs(cow[i].x-stop_pos[i]) << '\n';
  }
}
