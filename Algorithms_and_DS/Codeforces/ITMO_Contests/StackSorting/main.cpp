#include <bits/stdc++.h>

int main()
{
  int n, tmp; std::cin  >> n;
  std::stack<int> src, dest;
  while (n--)
  { std::cin >> tmp; src.push(tmp); }
  while(!src.empty())
  {
    int top = src.top();
    src.pop();
    while(!dest.empty() && dest.top() < top)
    {
      src.push(dest.top());
      dest.pop();
    }
    dest.push(top);
  }
  std::vector<int> v;
  while(!dest.empty())
  {
    v.push_back(dest.top());
    dest.pop();
  }
  for(auto& a : v) std::cout << a << " ";
}
