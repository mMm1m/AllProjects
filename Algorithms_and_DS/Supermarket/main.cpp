#include <bits/stdc++.h>

int m, n,p;
std::vector<int> A,B,T;
bool check(int time)
{
  std::vector<int> amount(m);
  int count = 0;
  for(int i = 0; i < m; ++i)
  {
    if(A[i] > 0)
      amount[i] = (time - B[i] - T[i])/A[i];
    else
    {
      amount[i] = ((B[i] + T[i]) > time) ? 0 : 1e6 ;
    }
  }
  std::sort(amount.begin(), amount.end());
  if(m >= n)
  {
    for(int i = m-1; i >= m-n; --i)
    {
      if(amount[i] <= 0) break;
      count += amount[i];
    }
  }
  else
  {
    for(int i = m-1; i >= 0; --i )
    {
      if(amount[i] <= 0) break;
      count += amount[i];
    }
  }
  return count<p;
}

int main()
{
  int a,b,t;
  std::cin >> m;
  for(int i = 0; i < m; ++i)
  {
    std::cin >> a >> b >> t;
    A.push_back(a) ; B.push_back(b); T.push_back(t);
  }
  std::cin >> n >> p;
  int left = 0, right = 10e18;
  while(left < right)
  {
    int mid = left + (right-left)/2;
    if(check(mid)) left = mid;
    else right = mid;
  }
  std::cout << left << " " << right << "\n";
}
