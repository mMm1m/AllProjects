#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> v(n); for(auto& a : v) std::cin >> a;
  int ones = 1, two = 1, max_one = 1, max_two = 1;
  for(int i = 1; i < n; i++) {
    if (v[i] == 1 && v[i - 1] == 1) { ++ones; max_one = std::max(ones, max_one); }
    else if (v[i] == 2 && v[i - 1] == 2) { ++two; max_two = std::max(two, max_two);}
    else {ones = 1;two = 1;}
  }
  std::cout << 2*
  std::min(max_one, max_two) << '\n';
}
