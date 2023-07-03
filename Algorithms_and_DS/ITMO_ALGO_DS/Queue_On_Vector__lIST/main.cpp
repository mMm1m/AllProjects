#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

namespace golchanskiy
{
  template < typename T >
  class Queue
  {
    public:
     Queue() = default;
     void push(T&);
     void pop();
     T front() const;
     T back() const;
     bool isEmpty() const;

    private:
     std::vector<T> vector_;
  };

  template < typename T >
  T golchanskiy::Queue< T >::front() const
  {
    if (isEmpty())
    {
      throw std::logic_error("Queue is empty!");
    }
    return vector_.front();
  }

  template < typename T >
  void golchanskiy::Queue< T >::push(T& value)
  {
    vector_.push_back(value);
  }
  template < typename T >
  void golchanskiy::Queue< T >::pop()
  {
    if (isEmpty())
    {
      throw std::logic_error("Queue is empty!");
    }
    vector_.pop_back();
  }
  template < typename T >
  bool golchanskiy::Queue< T >::isEmpty() const
  {
    return vector_.empty();
  }
}



int main()
{
  int n; std::cin >> n;
  golchanskiy::Queue<int> queue;
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
      queue.push(num);
    }
    else if(str[0] == '-')
    {
        if(!queue.isEmpty())
        {
          queue.front();
          queue.pop();
        }
    }
    --n;
  }
  return 0;
}
