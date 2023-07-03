#include <bits/stdc++.h>

int main()
{
  std::cout << "Hello, World!" << std::endl;
  return 0;
}


void sortArray(std::vector<int> &nums)
{
  std::vector<int> counting_sort(2, 0);
  for(int i = 0;  i< nums.size(); ++i)
  {
    ++counting_sort[nums[i]];
  }
  for(int i = 0; i <= 1; ++i)
  {
    int j = counting_sort[i];
    while(j != 0)
    {
      std::cout << i;
      --j;
    }
  }
}