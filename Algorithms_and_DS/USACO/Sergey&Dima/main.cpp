#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> v(n); for(auto& a : v)std::cin >> a;
  int s = 0, d = 0, left = 0, right = n-1, index = 0, tmp;
  while(left <= right)
  {
    if(v[left] > v[right])
    {
      tmp = v[left];
      ++left;
    }
    else
    {
      tmp = v[right];
      --right;
    }
    if((index)%2==0) s+= tmp;
    else d += tmp;
    ++index;
  }
  std::cout << s << " " << d << " ";
}
