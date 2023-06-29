#include <bits/stdc++.h>

int main()
{
  int num;
  while(scanf("%d", &num), num != 0)
  {
    std::string string, new_string;
    getline(std::cin, string);
    string.erase(std::remove(string.begin(), string.end(),' '), string.end());
    int start = 0;
    while(start < string.size())
    {
      std::string temp = string.substr(start,string.size()/num);
      std::reverse(temp.begin(), temp.end());
      new_string += temp;
      start += string.size()/num;
    }
    std::cout << new_string << '\n';
  }
}
