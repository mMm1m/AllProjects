#ifndef STACK_ON_VECTOR__LIST_QUEUE_H
#define STACK_ON_VECTOR__LIST_QUEUE_H

#include <stdexcept>
#include<bits/stdc++.h>
#include "Vector.h"

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
     golchanskiy::detail::Vector<T> vector_;
  };
}
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
  vector_.pop_front();
}
template < typename T >
bool golchanskiy::Queue< T >::isEmpty() const
{
  return vector_.empty();
}


#endif //STACK_ON_VECTOR__LIST_QUEUE_H
