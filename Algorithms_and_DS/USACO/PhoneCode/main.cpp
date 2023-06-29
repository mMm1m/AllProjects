#include <bits/stdc++.h>
using ll = long long;

int main()
{
  int n;
  std::cin >> n;
  std::string v[n];
  for(int i = 0; i < n; i++)
  {
    std::cin >> v[i];
  }
  ll answer = v[0].size();
  for(int i = 1; i < n; i++)
  {
    ll curr_prefix = 0;
    for(int j = 0; j < answer; j++)
    {
      if(v[i-1][j]==v[i][j])
        curr_prefix++;
      else
      {
        answer = std::min(curr_prefix,answer);
        break;
      }
    }
  }
  std::cout << answer;
}
