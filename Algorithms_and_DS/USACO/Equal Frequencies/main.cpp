#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while (t--)
  {
    int n;
    std::string str;
    std::vector< int > v(26, 0);
    std::cin >> n;
    std::cin >> str;
    for (int i = 0; i < str.size(); i++) v[str[i] - 'a']++;
    int answer = 1e9;
    for (int k = 1; k <= str.size(); k++)
    {
      if (str.size() % k != 0) continue;
      int curr = 0;
      for (int i = 0; i < str.size(); i++)
      {
        if (str[i] != 0)
          curr += std::abs(str[i] - k);
      }
      answer = std::min(answer,curr);
    }
    std::cout << answer << '\n';
  }
}