#include <bits/stdc++.h>

int n;
int left = 0, right = n, answer = 100;

int binary(int target, const std::vector<int>& vector)
{
  while(left <= right)
  {
    int med = left + (right-left)/2;
    if(vector[med] > target)
    {
      right = med;
      answer = std::min(answer, vector[med]);
    }
    else
    {
      left = med+1;
    }
  }
  return answer;
}

int main()
{
  std::cin >> n;
  std::vector<int> vector(n);
  for(int i = 0; i < n; i++)
    std::cin >> vector[i];

  std::sort(vector.begin(), vector.end());

  int target;
  std::cin >> target;
  std::cout << binary(target, vector);
}
