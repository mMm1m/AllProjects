#include <bits/stdc++.h>
using ll = long long;

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    ll n,m, max_row = 0, max_column = 0; std::cin >> n >> m;
    std::vector<std::vector<ll>> v(50, std::vector<ll>(50));
    for(int i = 0;  i< n; ++i)
    {
      for(int j = 0;  j < m; ++j)
      {
        std::cin >> v[i][j];
        if(v[i][j] > v[max_row][max_column]) {max_row = i; max_column=j;}
      }
    }
    ll height = std::max(max_row+1, n-max_row);
    ll width = std::max(max_column+1, m-max_column);
    std::cout << height*width << '\n';
  }
}
