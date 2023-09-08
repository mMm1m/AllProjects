#include <bits/stdc++.h>

int main()
{
  std::string string;
  getline(std::cin, string);
  std::stack<int> s, temp_number;
  int e = 1, curr = -1;
  for(int i = 0; i < string.size(); ++i)
  {
    if(std::isdigit(string[i]))
    {
      curr = 0;
      temp_number.push(string[i]-'0');
    }
    else
    {
      if(curr != -1) {
        while (!temp_number.empty()) {
          curr += e * temp_number.top();
          e *= 10;
          temp_number.pop();
        }
        s.push(curr);
      }
      e = 1; curr = -1;
      if(string[i] == '-' || string[i] == '+' || string[i] ==  '*' || string[i] ==  '/')
      {
        int first = s.top(), ans; s.pop();
        int second = s.top(); s.pop();
        if(string[i] == '-') s.push(first-second);
        if(string[i] == '+') s.push(first+second);
        if(string[i] == '*') s.push(first*second);
        if(string[i] == '/') s.push(first/second);
      }
    }
  }
  while(!s.empty())
  {
    std::cout << s.top() << " ";
    s.pop();
  }
}
