#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;

    int one = 0, two = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
      int val; std::cin >> val; sum += val;
      if(val==1) ++one; else ++two;
    }
    if(sum%2==1)
      std::cout << "NO\n";
    else
    {
      int target = sum/2;
      if(one==0 || one==1)
      {
        if(target*(1.0)/two<=2 && target%2==0)
          std::cout << "YES\n";
        else
          std::cout << "NO\n";
      }
      else
      {
        if(target-(2*two)<=one)
          std::cout << "YES\n";
        else
          std::cout << "NO\n";
      }
    }
  }
}
