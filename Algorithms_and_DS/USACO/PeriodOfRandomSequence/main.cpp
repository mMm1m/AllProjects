#include<cstdio>
#include <iostream>
#include <vector>

int a,b,c,d,e;
std::vector<int> u(100001);
int main()
{
  scanf("%d%d%d%d",&a,&b,&c,&d);
  while(!u[d])
    u[d]=++e,d=(a*d+b)%c;
  printf("%d\n",1+e-u[d]);
}