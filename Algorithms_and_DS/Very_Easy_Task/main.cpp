#include <bits/stdc++.h>

int main()
{
  int n, x, y, h, l, r, temp;
  std::cin>>n>>x>>y;
  int largest = x >= y ? x : y;
  int smallest = x < y ? x : y;
  l=0;


  r=(n-1)*largest;
  while (l != r)
  {
    temp=(l+r)/2;
    h=temp/x + temp/y;
    if (h<n-1) l=temp+1;
    else r=temp;
  }
  std::cout<<r+smallest;
  return 0;
}
