#include <bits/stdc++.h>
using ll = long long;

std::vector<ll> z(const std::string &s) {
  int n = (int)s.size();
  std::vector<ll> z_S(n);
  for (ll i = 1, l = 0, r= 0; i < n; i++) {
    if (i <= r) {
      z_S[i] = std::min(z_S[i - l], r - i + 1);
    }
    while (i + z_S[i] < n && s[z_S[i]] == s[i + z_S[i]]) {
      z_S[i]++;
    }
    if (i + z_S[i] - 1 > r) {
      l = i;
      r = i + z_S[i] - 1;
    }
  }
  return z_S;
}

int main()
{
  std::string str;
  std::cin >> str;
  auto v = z(str);
  for(int i = 0; i < v.size(); i++)
  {
    if(i+v[i]==v.size())
      std::cout << i << " ";
  }
  std::cout << str.size();
}
