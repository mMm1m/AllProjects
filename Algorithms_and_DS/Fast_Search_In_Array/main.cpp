#include <bits/stdc++.h>
const int constant = 1e9;
int main()
{
  int n, a; std::cin >> n;
  std::vector<int> start(n);
  // number / count
  for(int i = 0;  i< n; ++i)
  {
    std::cin >> a;
    start[i] = a;
  }
  std::sort(start.begin(), start.end());
  int k, l, r; std::cin >> k;
  for(int i = 0; i < k; ++i)
  {
    std::cin >> l >> r;
    std::cout << (std::upper_bound(start.begin(), start.end(), r)-start.begin()) - (std::lower_bound(start.begin(), start.end(), l)-start.begin()) << '\n';
  }
}
