#include <iostream>

int main()
{
  int t,n,i; std::cin>>t;
  while(t--)
  {
    i=1;std::cin>>n;
    while(i<=n/2)  std::cout<<i+n/2<<" "<<i++<<" ";
    if(n%2) std::cout<<n; std::cout<<std::endl;
  }
}
