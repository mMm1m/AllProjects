#include <bits/stdc++.h>

class CustomStack
{
  private:
   int min_value;
   int curr_size;
   std::vector<int> min;
  public:
   CustomStack() : min_value(INT_MAX), curr_size(-1) {}
   int get_min()
   {
     return min[curr_size];
   }
   void push(int val)
   {
     ++curr_size;
     if(val < min_value) min_value = val;
     min.push_back(min_value);
   }
   void pop()
   {
     --curr_size;
     min.pop_back();
   }
};

int main()
{
  int n, temp; std::cin >> n;
  auto stack_ = new CustomStack();
  for(int i = 0; i < n; ++i)
  {
    std::cin >> temp;
    if(temp == 1)
    {
      int b; std::cin >> b;
      stack_->push(b);
    }
    else if(temp == 2) stack_->pop();
    else std::cout << stack_->get_min() << "\n";
  }
  delete stack_;
}
