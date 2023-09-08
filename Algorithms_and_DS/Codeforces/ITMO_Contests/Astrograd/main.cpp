#include <bits/stdc++.h>

struct CustomQueueElement
{
  int el_id;
  CustomQueueElement(int i) : el_id(i) {}
};

class CustomQueue
{
  private:
   std::list<int> v;
   std::deque<CustomQueueElement> d;
  public:
   CustomQueue() = default;
   void push_back(CustomQueueElement c)
   {
     d.push_back(c);
     v.push_back(c.el_id);
   }
   void pop_front()
   {
     d.pop_front();
     v.pop_front();
   }
   void pop_back()
   {
     d.pop_back();
     v.pop_back();
   }
   int q_question(int idx)
   {
     int index = 0;
     for(auto& a : v)
     {
       if(a == idx) break;
       ++index;
     }
     return index;
   }
   int queue_question()
   {return d.front().el_id;}

};

int main()
{
  int n, temp; std::cin >> n;
  CustomQueue q;
  for(int i = 0; i < n; ++i)
  {
    std::cin >> temp;
    if(temp == 1)
    {
      int b; std::cin >> b;
      q.push_back(CustomQueueElement(b));
    }
    else if(temp == 2) q.pop_front();
    else if(temp == 3) q.pop_back();
    else if(temp == 4)
    {
      int idx; std::cin >> idx;
      std::cout << q.q_question(idx) << '\n';
    }
    else if(temp == 5) std::cout << q.queue_question() << '\n';
  }
}
