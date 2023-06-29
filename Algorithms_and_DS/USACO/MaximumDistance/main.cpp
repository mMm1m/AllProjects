#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> x_(n), y_(n);
  for(int& a : x_)
    std::cin >> a;
  for(int& b : y_)
    std::cin >> b;
  int maximum = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      int curr = static_cast<int>(std::pow(x_[i] - x_[j],2))
        + static_cast<int>(std::pow(y_[i] - y_[j],2));
      maximum = std::max(maximum, curr);
    }
  }
  std::cout << maximum;
  return 0;
}
