#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    std::string str; std::cin >> str;
    if((str[0]=='2'&&str[n-3]=='0'&&str[n-2]=='2'&&str[n-1]=='0') || (str[0]=='2'&&str[1]=='0'&&str[n-2]=='2'&&str[n-1]=='0')
    || (str[0]=='2'&&str[1]=='0'&&str[2]=='2'&&str[n-1]=='0') ||
      (str[0]=='2'&&str[1]=='0'&&str[2]=='2'&&str[3]=='0') || (str[n-4]=='2'&&str[n-3]=='0'&&str[n-2]=='2'&&str[n-1]=='0'))
      std::cout << "YES\n";
    else std::cout << "NO\n";
  }
}
