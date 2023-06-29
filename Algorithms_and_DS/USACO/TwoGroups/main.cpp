#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int n; std::cin >> n;
    std::vector<int> v(n); for(auto& a : v) std::cout << a;
    std::sort(v.begin(), v.end());
    if(n==1) std::cout << v[0] << '\n';
    else if(n==2) std::cout << std::abs(v[0])-std::abs(v[1]) << '\n';
    else
    {
      if(n%2==0)
      {
        int left = 0, right = n-1, f = 0, s = 0;
        while(left < right)
        {
          f+=v[left]; s+=v[right];
          ++left; --right;
        }
        std::cout << std::abs(f)-std::abs(s) << '\n';
      }
      else
      {
        int left = 0, right = n-1, f = 0, s = 0;
        while(right-left>=2)
        {
          f+=v[left]; s+=v[right];
          ++left; --right;
        }
        std::cout << std::min(std::abs((f)+v[n/2])-(std::abs(s)), std::abs(f)-(std::abs(s)+v[n/2]));
      }
    }
  }
}
