#include <bits/stdc++.h>
using ll = long long;

int main()
{
  std::vector<ll> vector(3, 0);
  ll a,b,c,m;
  std::cin >> a >> b >> c;
  vector[0] = a; vector[1] = b; vector[2] = c;

  std::cin >> m;
  std::vector<std::pair<ll,std::string>> mouse;
  ll sum = std::accumulate(vector.begin(), vector.end(), 0), answer = 0;
  ll temp_sum = std::accumulate(vector.begin(), vector.end(), 0);
  for(int i = 0; i < m; i++)
  {
    ll cost; std::string name;
    std::cin >> cost >> name;
    mouse.push_back({cost, name});
  }
  std::sort(mouse.begin(), mouse.end());
  for(int i = 0; i < m; i++)
  {
    if(mouse[i].second=="USB" && vector[0] != 0)
    {
      --vector[0];
      --sum;
      answer += mouse[i].first;
    }
    else if(mouse[i].second=="USB" && vector[0] == 0 && vector[2] != 0)
    {
      --vector[2];
      --sum;
      answer += mouse[i].first;
    }
    else if(mouse[i].second=="PS/2" && vector[1] != 0)
    {
      --vector[1];
      --sum;
      answer += mouse[i].first;
    }
    else if(mouse[i].second=="PS/2" && vector[1] == 0 && vector[2] != 0)
    {
      --vector[2];
      --sum;
      answer += mouse[i].first;
    }
  }
  ll end_sum = std::accumulate(vector.begin(), vector.end(), 0);
  std::cout << temp_sum - end_sum << " " << answer;

}
