// C++ Program for counting sort
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define RANGE 255

void countSort(std::vector<int>& arr, int n)
{
  int output[n];
  int count[101], i;
  memset(count, 0, sizeof(count));

  for (i = 0; arr[i]; ++i)
    ++count[arr[i]];
  for (i = 1; i <= 100; ++i)
    count[i] += count[i - 1];
  for (i = 0; arr[i]; ++i) {
    output[count[arr[i]] - 1] = arr[i];
    --count[arr[i]];
  }
  for (i = 0; arr[i]; ++i)
    arr[i] = output[i];
}

int main()
{
  int n;
  std::vector<int> arr;
  while(std::cin >> n)
  {
    arr.push_back(n);
  }
  countSort(arr,(int)arr.size());
  for(auto& a : arr)
    std::cout << a;
  return 0;
}

