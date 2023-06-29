#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n; std::cin >> n;
    std::vector<std::pair<int,int>> even, odd;

    for(int i = 0; i < n; i++)
    {
      int val; std::cin >> val;
      (val%2==0) ? even.push_back({val,i+1}) : odd.push_back({val,i+1}) ;

    }
    if(even.size()>=1)
      std::cout << 1 << '\n' << even[0].second << '\n';
    else if(odd.size()>=2)
      std::cout << 2 << '\n' << odd[0].second << " " << odd[1].second << '\n';
    else std::cout << -1 << '\n';
  }
}
