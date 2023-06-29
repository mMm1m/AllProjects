#include <bits/stdc++.h>

int main()
{
  int t;
  std ::cin >> t;
  while(t--)
  {
    int n, sum = 0;
    std::cin >> n;
    std::vector<int> v(n), minus;
    for(int i = 0; i < n; i++){
      std::cin >> v[i];
      if(v[i]==-1 ) minus.push_back(i);
      sum += v[i];
    }
    if(minus.empty())
    {
      std::cout << sum-4 << '\n';
      continue;
    }
    if(minus.size()==1)
    {
      std::cout << sum << '\n';
      continue;
    }
    if(minus.size()>1)
    {
      bool flag = true;
    for(int i = 1; i <minus.size(); i++)
    {
      if(minus[i]-1==minus[i-1]){
        std::cout << sum+4 << '\n';
        flag = false;
        break;
      }
    } if(!flag) continue;
    }
    std::cout << sum << '\n';
  }
}
