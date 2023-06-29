#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;

  int a[n] , b[n] , besti [n];
  for(int i = 0; i < n; i++) std::cin>>a[i];
  for(int i = 0; i < n; i++) std::cin>>b[i];

  for(int i = 0; i < n; i++) besti[a[i]-1]=b[i];

  for(int i = 0; i < n; i++)std::cout<<besti[i]<<" ";
}
