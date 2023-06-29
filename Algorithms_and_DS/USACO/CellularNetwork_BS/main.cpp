#include <bits/stdc++.h>

int binary(const std::vector<int>& vector, int city)
{
  int left = 0, right = vector.size();
  while(left < right)
  {
    int mid = left + (right-left)/2;
    if(vector[mid] >= city)
    {
      right = mid;
    }
    else
    {
      left = mid+1;
    }
  }
  return left;
}

int main()
{
  int n,m;
  std::cin >> n >> m;
  std::vector<int> towers(m), cities(n);
  for(int i = 0; i < n; i++)
    std::cin >> cities[i];

  for(int i = 0; i < m; i++)
    std::cin >> towers[i];



}
