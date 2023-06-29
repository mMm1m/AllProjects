#include <bits/stdc++.h>


int main()
{
  int n,t;
  std::cin >> n >> t;
  std::vector<int> cows(n);
  for( int i = 0; i < n; i++)
    std::cin >> cows[i];

  std::priority_queue<int> pq;
  int left = 0, right = n, ans = n;
  while(left <= right)
  {
    int middle = left + (right-left)/2, time = 0;
    int j = 0;
    while(pq.size() < n && j < middle)
    {
      pq.push(-cows[j]);
      j++;
    }

    while(pq.size())
    {
      time += std::max(0, -pq.top()-time);
      pq.pop();
      if(j < n)
      {
        pq.push(-(cows[j]+time));
        j++;
      }
    }

    if(time > t)
    {
      left = middle+1;
    }
    else
    {
      ans = std::min(ans,middle);
      right = middle - 1;
    }
  }
}
