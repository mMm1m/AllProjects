#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::deque<std::string> v(n+1);
  for(int i = 0; i < n; i++)
  {
    v[i] += "0";
    std::string val;
    std::cin >> val;
    v[i] += val;
  }
  int max = 0, start;
  for(int i = 0; i < 8; i++)
  {
    int curr = 0;
    for(int j = 0; j < n; j++)
      curr = curr + (int)v[j][i];
    if(i==0)
      start = curr;
    max = std::max(max, curr);
  }
  std::cout << max - start;
}
