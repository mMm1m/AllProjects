#include <bits/stdc++.h>

int main()
{
  freopen("citystate.in", "r", stdin);
  freopen("citystate.out", "w", stdout);
  int n;
  std::cin >> n;
  std::vector<std::pair<std::string, std::string>> pairs;
  std::map<std::string, int> map;
  for(int i = 0; i < n; i++) {
    std::string city, state;
    std::cin >> city >> state;
    city = city.substr(0,2);
    pairs.push_back({city, state});
  }

   int count = 0;
  for(const auto& [city, state] : pairs)
  {
    if(state != city)
      count += map[state+city];
    map[city+state]++;
  }
  std::cout << count;

  /*for(int i = 0; i < vector.size();i++)
    std::cout << vector[i] << "\n";*/


  /*for(auto it = multimap.begin(); it != multimap.end(); it++)
    std::cout << it->first << " " << it->second << "\n";*/

}
