#include <bits/stdc++.h>

void solution(int start, int end, int k)
{
  int sum;
  if(start == end)
  {
    std::cout << "!" << start << '\n';
    return;
  }

  int middle = start + (end-start)/2;
  std::cin >> sum;
  std::cout << "?" << start << middle << '\n';
  if((middle-start+1)-sum >= k)
  {
    solution(start,middle,k);
  }
  else
  {
    solution(middle+1, end, k-((middle-start+1)-sum));
  }
}

int main()
{
  int n,m,k;
  std::cin >> n >> m >> k;
  solution(1,n,k);
}
