#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> vector(n);
  for(int& a:vector)
    std::cin >> a;

  int even = 0, odd = 0;
  for(int a : vector)
  {
    if(a%2==0) even++;
    else odd++;
  }

  while(odd > even)
  {
    odd -= 2;
    even++;
  }

  if(even-odd > 1)
    even = odd+1;

  std::cout << even+odd;
}
