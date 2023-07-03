#include <iostream>
#include <cmath>
#include "Stack.h"

int main()
{
  int n; std::cin >> n;
  golchanskiy::Stack<int> stack;
  while(n)
  {
    std::string str;
    getline(std::cin, str);
    if(str[0] == '+')
    {
      int num = 0, index = 0;
      for(int i = str.size()-1; i >= 0; i--)
      {
        if(str[i]-'0' >= 0 && str[i]-'0' <= 9)
        {
          num += ((str[i]-'0')*static_cast<int>(std::pow(10,index++)));
        }
      }
      stack.push(num);
    }
    else if(str[0] == '-')
    {
        if(!stack.isEmpty())
        {
          stack.top();
          stack.pop();
        }
    }
    --n;
  }
  return 0;
}
