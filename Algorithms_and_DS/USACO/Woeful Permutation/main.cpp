#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    if(n==1) {std::cout << 1 << '\n';}
    else if(n==2) {std::cout << 2 << " " << 1 << '\n';}
    else
    {
      if(n%2==0)
      {
        std::cout << 2 << " " << 1 << " ";
        for(int i = 3; i <=n; i++)
        {
          if(i%2!=0){std::cout << i+1 << " ";}
          else{std::cout << i-1 << " ";}
        }
        std::cout << '\n';
      }
      else
      {
        std::cout << 1 << " ";
        for(int i = 2; i <= n; i++)
        {
          if(i%2!=0){std::cout << i-1 << " ";}
          else{std::cout << i+1 << " ";}
        }
        std::cout << '\n';
      }
    }
  }
}
