#include <bits/stdc++.h>

void count_sort(std::vector<std::string>& input, int n, int t)
{
  std::vector<int> temp(27);
  std::vector<std::string> ans(n);
  for(auto& a : input) {++temp[a[t]-'a'+1];}
  for(int i = 1; i < 27; ++i) {temp[i] += temp[i-1];}
  for(auto& string : input) ans[temp[string[t]-'a']++] = string;
  std::copy(ans.begin(), ans.end(), input.begin());
}

void radix_sort(std::vector<std::string>& input, int n, int m,int k)
{
  for(int i = 0; i < k; ++i)
  {
    count_sort(input, n, m-i-1);
  }
}

int main()
{
  int n,m,k; std::cin >> n >> m >> k;
  std::vector<std::string> v_str;
  for(int i = 0; i < n; ++i)
  {
    std::string str; std::cin >> str;
    v_str.push_back(str);
  }
  radix_sort(v_str, n, m, k);
  for(auto& a : v_str) std::cout << a << '\n';
}
