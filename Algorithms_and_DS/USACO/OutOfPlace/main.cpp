#include <bits/stdc++.h>

int less(std::vector<int>& arr, int n)
{
  for(int i = 1; i < n; i++)
  {
    if(arr[i] < arr[i-1])
      return i;
  }
  return 0;
}

int main()
{
  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);
  int n;
  std::cin >> n;
  std::vector<int> vector(n);
  std::vector<int> sorted(n);
  for(int i = 0; i < n; i++)
  {
    int value;
    std::cin >> value;
    vector[i] = sorted[i] = value;
  }

  int count  = 0;
  std::sort(sorted.begin(), sorted.end());
  for(int i  =0 ; i < n; i++)
  {
    if(vector[i] != sorted[i])
      count++;
  }

  std::cout << count - 1;

}
