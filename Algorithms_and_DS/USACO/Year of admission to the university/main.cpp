#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for(int i = 0; i < n; i++)
    std::cin >> v[i];
  if(n==1)
  {
    std::cout << v[0];
    return 0;
  }
  std::sort(v.begin(), v.end());
  std::cout << v[n/2];
}
