#include <bits/stdc++.h>

int solution(const std::string& str)
{
  int sum = 0;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z') sum += (str[i] - 'a' + 1);
    else if (str[i] >= 'A' && str[i] <= 'Z') sum += (str[i] - 'A' + 1);
  }
  return (sum%9==0) ? 9 : sum%9;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::string str1, str2;
  while(getline(std::cin, str1))
  {
    getline(std::cin, str2);
    int first = solution(str1), second = solution(str2);
    double ans = std::min(first*1.0/second, second*1.0/first);
    std::cout << ans*100.0 << " " << "%" << '\n';
  }
}
