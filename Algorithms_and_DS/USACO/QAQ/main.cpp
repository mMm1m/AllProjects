#include <bits/stdc++.h>

int main()
{
  std::string str; std::cin >> str;
  int a = 0, q = 0, answer = 0;
  for(int i = 0; i < str.size(); i++)
  {
    if(str[i]=='A') a += q;
    else if(str[i]=='Q') {answer += a;++q;}
  }
  std::cout << answer;
}
