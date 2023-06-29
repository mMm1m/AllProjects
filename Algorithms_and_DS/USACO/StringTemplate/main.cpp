#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::string> v;

  std::string answer;

  int size;
  for(int i = 0; i < n; i++)
  {
    std::string str;
    std::cin >> str;
    size = str.size();
    v.push_back(str);
  }
  for(int i = 0; i < size; i++)
  {
    bool flag = false;
    std::set<char> letters;
    for(int j = 0; j < n; j++)
    {
      if(v[j][i]=='?')
        flag = true;
      else
        letters.insert(v[j][i]);
    }
    if(letters.size()>=2)
      answer.push_back('?');
    if(letters.size()==0 && flag) answer.push_back('x');
    if((flag && letters.size()==1) || letters.size()==1) answer.push_back(*letters.begin());
  }
  std::cout << answer;
}
