#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include "Functions.h"
#include "ExprPart.h"

using q_s = std::queue<std::string>;
using q_e = std::queue<golchanskiy::ExprPart>;

namespace
{
  long long multiplication(long long first, long long second)
  {
    long long max = std::numeric_limits<long long>::max();
    long long min = std::numeric_limits<long long>::min();
    if(first > 0 && second > 0 || first < 0 && second < 0)
    {
      if(first > max / second)
      {
        throw "Overflow";
      }
    }
    else if(first > 0 && second < 0)
    {
      if(second < min / first)
      {
        throw "Overflow";
      }
    }
    else if(first < 0 && second > 0)
    {
      if(first < min / second)
      {
        throw "Overflow";
      }
    }
    return first*second;
  }


  long long addition(long long first, long long second)
  {
    long long max = std::numeric_limits<long long>::max();
    long long min = std::numeric_limits<long long>::min();
    if(first > 0 && second > 0)
    {
      if(first > max - second)
      {
        throw "Overflow";
      }
    }
    else if(first < 0 && second < 0)
    {
      if(first < min - second)
      {
        throw "Overflow";
      }
    }
    return first+second;

  }
}

namespace golchanskiy {
  std::queue< std::string > golchanskiy::input(std::istream& stream)
  {
    q_s qS;
    while (!stream.eof()) {
      if (stream.peek() && stream.eof()) break;
      std::string string;
      getline(stream, string);
      qS.push(string);
    }
    return qS;
  }

  bool golchanskiy::isNumber(std::string string)
  {
    bool val = true;
    for(int i = 0; i < string.size(); ++i)
    {
      val = val && std::isdigit(string[i]);
    }
    return val;
  }

  bool golchanskiy::isOperation(char c)
  {
    return c == ('+' | '-' | '*' | '/');
  }

  std::queue<golchanskiy::ExprPart> golchanskiy::stringToQueueExprType(std::string string)
  {
    std::string str = "";
    std::queue<golchanskiy::ExprPart> queue;
    for(int i = 0; i < string.size(); ++i)
    {
      if(string[i] != ' ')
      {
        if(isalpha(string[i])) throw "It can't be a letter";
        if(isOperation(string[i]))
        {
          if(isNumber(str))
          {
            queue.push(ExprPart(std::stoll(str)));
            str = "";
          }
          queue.push(ExprPart(string[i]));
        }
      }
      if (!str.empty())
      {
        if (isNumber(str))
        {
          queue.push(ExprPart(std::stoll(str)));
        }
        else
        {
          queue.push(ExprPart(str[0]));
        }
      }
    }
    return queue;
  }

  // include stringToExprType(std::string) - function
  std::queue< std::queue< golchanskiy::ExprPart>> golchanskiy::convert(std::queue< std::string > q)
  {
    std::queue<std::queue< golchanskiy::ExprPart>> qES;
    while(!q.empty())
    {
      auto tmp = q.front();
      q.pop();
      std::queue< golchanskiy::ExprPart> queue = stringToQueueExprType(tmp);
      infixToPostfix(queue);
      qES.push(queue);
    }
    return qES;
  }


  // I need this function only with brackets. Without brackets
  // enough only stringToExpr - function.
  /*void golchanskiy::infixToPostfix(std::queue< golchanskiy::ExprPart >)
  {

  }*/

  long long golchanskiy::calculation(std::queue< golchanskiy::ExprPart > queue)
  {
    std::stack<long long> stack;
    while(!queue.empty())
    {
      golchanskiy::ExprPart el = queue.front();
      queue.pop();
      if(el.getElement() == golchanskiy::ExprPartElement::OPERAND) stack.push(el.getOperand());
      if(el.getElement() == golchanskiy::ExprPartElement::OPERATOR)
      {
        long long first = stack.top(); stack.pop();
        long long second = stack.top(); stack.pop();
        if(el.getOperator() == '+')
        {
          stack.push(::addition(first, second));
        }
        else if(el.getOperator() == '*')
        {
          stack.push(::multiplication(first, second));
        }
        else if(el.getOperator() == '-')
        {
          stack.push(::addition(first, second*(-1)));
        }
        else if(el.getOperator() == '/')
        {
          if(second == 0)
          {
            throw "Divided by zero";
          }
          stack.push(first/second);
        }
      }
    }
    return stack.top();
  }

  void golchanskiy::output(std::ostream& o_stream, std::stack< long long > stack)
  {
    while(!stack.empty())
    {
      long long top = stack.top();
      stack.pop();
      o_stream << top << " ";
    }
  }
}