#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(auto& a : v) std::cin >> a;
    int left = 0, right = n-1;
    if (n==1) {std::cout << v[0] << '\n';}
    else {
      while (left < right) {
        std::cout << v[left] << " " << v[right] << " ";
        ++left; --right;
      }
      if(left==right) std::cout << v[left];
      std::cout << '\n';
    }
  }
}
