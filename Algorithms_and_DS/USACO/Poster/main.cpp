#include <bits/stdc++.h>

void move_right(std::string str, int n)
{
    for(int i = 0; i < n; i++) {
      std::cout << "PRINT " << str[i] << '\n';
      if (i != n - 1)
        std::cout << "RIGHT" << '\n';
    }
}

void move_left(std::string str, int n)
{
    for(int i = n-1; i >= 0; i--)
    {
      std::cout << "PRINT " << str[i] << '\n';
      if(i != 0)
        std::cout << "LEFT" << '\n';
    }
}

int main()
{
  int n,k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  if(k==1)
    move_right(str, n);
  else if(k==n)
    move_left(str,n);
  else
  {
    if(n-k < k-1)
    {
      for(int i = 0; i<n-k; i++)
        std::cout << "RIGHT" << '\n';
      move_left(str,n);
    }
    else
    {
      for(int i = 0; i<k-1; i++)
        std::cout << "LEFT" << '\n';
      move_right(str,n);
    }
  }
}
