#include <bits/stdc++.h>

inline bool cmp(const std::string& str1, const std::string& str2)
{
  return str1 + str2 < str2 + str1;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::string> vector;
  for(int i = 0; i < n; i++)
  {
    std::string str;
    std::cin >> str;
    vector.push_back(str);
  }

  std::sort(vector.begin(), vector.end(), cmp);
  std::string total = "";
  for(auto& a : vector)
    total += a;
  std::cout << total << "\n";
}
