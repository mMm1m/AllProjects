#ifndef QUEUE_ON_VECTOR__LIST_STACK_H
#define QUEUE_ON_VECTOR__LIST_STACK_H
#include <iostream>
#include "Vector.h"

namespace golchanskiy {
  template< typename T >
  class Stack {
    public:
     Stack() = default;

     void push(T&);

     void pop();

     T top() const;

     bool isEmpty() const;

    private:
     detail::Vector< T > vector_;
  };
}

template < typename T >
void golchanskiy::Stack< T >::push(T& value)
{
  vector_.push_back(value);
}
template < typename T >
T golchanskiy::Stack< T >::top() const
{
  if (isEmpty())
  {
    throw std::logic_error("Stack is empty!");
  }
  return vector_.back();
}
template < typename T >
void golchanskiy::Stack< T >::pop()
{
  if (isEmpty())
  {
    throw std::logic_error("Stack is empty!");
  }
  vector_.pop_back();
}
template < typename T >
bool golchanskiy::Stack< T >::isEmpty() const
{
  return vector_.empty();
}

#endif //QUEUE_ON_VECTOR__LIST_STACK_H
