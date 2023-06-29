#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> vector;
  while(n--)
  {
    vector.clear();
    int number, homes;
    std::cin >> number;
    for(int i = 0; i < number; i++)
    {
      std::cin >> homes;
      vector.push_back(homes);
    }
    std::sort(vector.begin(), vector.end());
    int med;
      med = vector.size()/2;
    std::swap(vector[0], vector[med]);
    int sum = 0;
    for(int first = 1; first < vector.size(); first++)
      sum += (std::abs(vector[first] - vector[0]));
    std::cout << sum << "\n";
  }
}
