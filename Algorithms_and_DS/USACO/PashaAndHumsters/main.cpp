#include <bits/stdc++.h>

int main()
{
  int n,a,b;
  std::cin >> n >> a >> b;
  std::vector<int> apples(n);
  for(int i = 0; i < a; i++)
  {
    int k;
    std::cin >> k;
    if(apples[k-1]==0)
      apples[k-1] = 1;
  }
  for(int i = 0; i < b; i++)
  {
    int k;
    std::cin >> k;
    if(apples[k-1]==0)
      apples[k-1] = 2;
  }
  for(auto& a : apples)
    std::cout << a << " ";
}
