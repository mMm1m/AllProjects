#include <iostream>
#include <random>
#include <cstring>

int main()
{
  int n = 10, b = 5;
  int array[n], arr_temp[n];
  for(int i = 0; i < n; i++)
  {
    array[i] = static_cast<int>(rand() % (static_cast<int>(std::pow(n,3) - b + 1)));
  }
  strcpy(reinterpret_cast<char*>(arr_temp), reinterpret_cast<const char*>(array));
  for(int a : arr_temp)
  {
    std::cout << a << " ";
  }
  return 0;
}
