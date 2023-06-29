#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  int count = 0;
  for(auto& a : v)
    std::cin >> a;

  for (int i = 0; i < n; i++)
    if (i + 1 < n)
      if (v[i] > v[i + 1])
      {
        count++;
      }
  std::cout << count;
}