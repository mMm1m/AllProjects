#include <bits/stdc++.h>

int main()
{
  int up, down;
  std::cin >> up >> down;
  std::vector<int> result;
  if(up>down)
  {
    int k = up+down+1-up;
    for(int i = 0; i < up+1;i++)
      result.push_back(k++);
    k = (up+down+1-up)-1;
    for(int i = up+1; i < up+down+1;i++)
      result.push_back(k++);
  }
  else
  {
    int k = up+down+1-up;
    for(int i = 0; i < down+1;i++)
      result.push_back(k--);
    k = (up+down+1-up)+1;
    for(int i = down+1; i < up+down+1;i++)
      result.push_back(k++);
  }
  for(auto& a : result)
  std::cout << a << " ";
}
