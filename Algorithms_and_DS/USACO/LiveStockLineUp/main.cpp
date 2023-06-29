#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector< std::pair<std::string, std::string>> vector(n);
  std::string X, must, be, milked, beside, Y;
  for(int i = 0; i < n; i++)
  {
    std::cin >> X >> must >> be >> milked >> beside >> Y;
    std::pair<std::string, std::string> pair = std::make_pair(X,Y);
    vector.push_back(pair);
  }

  std::vector< std::string > cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
  std::sort(cows.begin(), cows.end());
  while(std::next_permutation(cows.begin(), cows.end()))
  {
    bool indicator = true;
    for(auto pointer : vector)
    {
      // find first and second pair element in the cow-vector
      auto first = std::find(cows.begin(), cows.end(), pointer.first);
      auto second = std::find(cows.begin(), cows.end(), pointer.second);
      if(std::abs(first - second) != 1)
        indicator = false;
    }
    if(indicator)
      break;
  }
  for(auto cow : cows)
    std::cout << cow << "\n";
}
