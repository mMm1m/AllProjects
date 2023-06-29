#include<bits/stdc++.h>

int t,n,a[100005];
int main()
{
  std::cin>>t;
  while(t--)
  {
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
      std::cin>>a[i];
      a[i]+=a[i-1];
    }
    std::cout<<a[n-a[n]]<<'\n';
  }
}