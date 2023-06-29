#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> vector(n);
  for(int i = 0; i < n; i++)
    std::cin >> vector[i];

  std::sort(vector.begin(), vector.end());

  int target, left = 0, right = n;
  std::cin >> target;
  while(left < right)
  {
    int med = left + (right-left)/2;
    if(vector[med] == target)
    {
      std::cout << "Find!!!" << '\n';
      return 0;
    }
    if(vector[med] < target)
      left = med + 1;
    else
      right = med;
  }
  std::cout << "Not find" << '\n';
}
