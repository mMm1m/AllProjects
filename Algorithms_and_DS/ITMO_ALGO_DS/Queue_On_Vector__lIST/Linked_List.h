#ifndef STACK_ON_VECTOR__LIST_LINKED_LIST_H
#define STACK_ON_VECTOR__LIST_LINKED_LIST_H

#include <iostream>

namespace golchanskiy
{
  namespace detail
  {
    template<typename T>
    struct Node
    {
      Node* next;
      T data;
    };

    template<class T, typename NodeType = Node<T>>
    class List
    {
      public:
       List();
       List(const List &);
       List(List &&) noexcept;
       ~List();
       List &operator=(const List &);
       List &operator=(List &&) noexcept;
       void swap(List &) noexcept;
       bool isEmpty() const;
       size_t getSize() const;
       const T& front() const;
       const T& back() const;
       void clear();
       void pushBack(const T &);
       void pushFront(const T &);
       void popFront();
      protected:
       NodeType* head_;
       NodeType* tail_;
       size_t size_;
    };

    template<typename T,typename NodeType>
    golchanskiy::detail::List<T, NodeType>::List() : head_(nullptr), tail_(nullptr), size_(0) {}

    template<typename T,typename NodeType>
    golchanskiy::detail::List<T, NodeType>::List(const List & other) : head_(nullptr), tail_(nullptr), size_(0)
    {
      if(!other.isEmpty())
      {
        try
        {
          NodeType* curr = other.head_;
          do{
            pushBack(curr->data);
            curr = curr->next;
          } while(curr);
        }
        catch(...)
        {
          clear();
          throw;
        }
      }
    }

    template<typename T,typename NodeType>
    golchanskiy::detail::List<T, NodeType>::List(List && other) noexcept : head_(other.head_), tail_(other.tail_),
                                                                           size_(other.size_)
    {
      other.head_ = nullptr;
      other.tail_ = nullptr;
    }

    template<typename T,typename NodeType>
    golchanskiy::detail::List<T, NodeType>::~List()
    {
      clear();
    }

    template<typename T,typename NodeType>
    golchanskiy::detail::List<T, NodeType>::List& List<T, NodeType>::operator=(const List & other)
    {
      this->swap(other);
      return *this;
    }

    template<typename T,typename NodeType>
    golchanskiy::detail::List<T, NodeType>::List& List<T, NodeType>::operator=(List && other) noexcept
    {
      this->swap(other);
      other.clear();
      return *this;
    }

    template<typename T, typename NodeType>
    void golchanskiy::detail::List<T, NodeType>::swap(List & other) noexcept
    {
      std::swap(head_, other.head_);
      std::swap(tail_, other.tail_);
    }

    template<typename T, typename NodeType>
    bool golchanskiy::detail::List<T, NodeType>::isEmpty() const
    {
      return size_ == 0;
    }

    template<typename T, typename NodeType>
    size_t golchanskiy::detail::List<T, NodeType>::getSize() const
    {
      return size_;
    }

    template<typename T, typename NodeType>
    const T& golchanskiy::detail::List<T, NodeType>::front() const
    {
      if(head_ == nullptr)
      {
        throw std::logic_error("Try to bring element from empty");
      }
      return head_->data;
    }

    template<typename T, typename NodeType>
    const T& golchanskiy::detail::List<T, NodeType>::back() const
    {
      if(head_ == nullptr)
      {
        throw std::logic_error("Try to bring element from empty");
      }
      return tail_->data;
    }

    template<typename T, typename NodeType>
    void golchanskiy::detail::List<T, NodeType>::clear()
    {
      while(head_)
      {
        auto curr = head_;
        head_ = head_->next;
        delete curr;
        --size_;
      }
    }

    template<typename T, typename NodeType>
    void golchanskiy::detail::List<T, NodeType>::pushBack(const T & value)
    {
      if(size_ == 0)
      {
        NodeType* temp = {value, nullptr};
        head_ = temp;
        tail_ = head_;
      }
      else
      {
        tail_->next = new NodeType{value, nullptr};
        tail_ = tail_->next;
      }
    }

    template<typename T, typename NodeType>
    void golchanskiy::detail::List<T, NodeType>::pushFront(const T & value)
    {
      if(size_ == 0)
      {
        NodeType* temp = {value, nullptr};
        head_ = temp;
        tail_ = head_;
      }
      else
      {
        tail_->next = new NodeType{value, nullptr};
        tail_ = tail_->next;
      }
    }

    template<typename T, typename NodeType>
    void golchanskiy::detail::List<T, NodeType>::popFront()
    {
      if(size_ == 0)
      {
        throw std::logic_error("Deletion from empty list");
      }
      auto tmp(head_);
      head_ = head_->next;
      delete tmp;
      --size_;
    }

  }
}

#endif //STACK_ON_VECTOR__LIST_LINKED_LIST_H
