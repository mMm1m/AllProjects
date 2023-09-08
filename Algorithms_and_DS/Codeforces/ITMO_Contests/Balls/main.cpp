#include <bits/stdc++.h>

int main()
{
  int n, temp, count = 0; std::cin >> n;
  std::stack<int> stack,temp_stack;
  for(int i = 0; i < n; ++i)
  {
    std::cin >> temp;
    if(!temp_stack.empty())
    {
      if(temp_stack.top() != temp)
      {
        if(temp_stack.size() >= 3)
        {
          count += temp_stack.size();
          while(!temp_stack.empty()) temp_stack.pop();
        }
        else
        {
          while(!temp_stack.empty()) {
            stack.push(temp_stack.top());
            temp_stack.pop();
          }
        }
      }
    }
    temp_stack.push(temp);
    while(!stack.empty())
    {
      if(stack.top() == temp)
      {
        temp_stack.push(stack.top());
        stack.pop();
      }
      else break;
    }
    //std::cout << stack.size() << " " << temp_stack.size() << '\n';
  }
  if(temp_stack.size() >= 3)
  {
    count += temp_stack.size();
    while(!temp_stack.empty()) temp_stack.pop();
  }
  std::cout <<  count;
}
