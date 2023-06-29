#include <bits/stdc++.h>

int main()
{
  int n,q;
  std::cin >> n >> q;
  std::string str; std::cin >> str;
  std::vector<int> v(n+1); v[0] = 0;
  for(int i = 1; i <= n; i++){v[i] = str[i-1]-'a'+1;v[i] += v[i-1];}
  for(int i = 0;  i< q; i++)
  {
    int l,r;
    std::cin >> l >> r;
    std::cout << v[r]-v[l-1] << '\n';
  }
}
