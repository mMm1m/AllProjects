#include <bits/stdc++.h>

int main()
{
  std::vector<int> v(1001,0);
  int n;
  std::cin >> n;
  for(int i = 0; i < n-1; i++)
  {
    int a,b;
    std::cin >> a >> b;
    v[a]++; v[b]++;
  }
  int remote = 0;
  for(int i = 0; i < 1001; i++)
    if(v[i]==1) remote++;
  std::cout << remote;
}
