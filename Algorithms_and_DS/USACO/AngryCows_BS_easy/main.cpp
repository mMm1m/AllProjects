#include <bits/stdc++.h>



int main()
{
  int n, k;
  std::cin >> n >> k;
  std::vector<int> positions(n);
  for(int i = 0; i < n; i++)
    std::cin >> positions[i];

  std::sort(positions.begin(), positions.end());
  int left = 0, right = 1e9;
  while(left < right)
  {
    int med = left + (right-left)/2, used_cows = 0, last_cow = 0;
    while(last_cow < n)
    {
        used_cows++;
        int curr = last_cow + 1;
        while(curr < n && positions[curr] <= positions[last_cow] + 2*med)
        {
          curr++;
        }
        last_cow = curr;
    }
    if(used_cows <= k)
    {
      right = med;
    }
    else
    {
      left = med + 1;
    }
  }
  std::cout << left;
}
