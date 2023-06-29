#include <bits/stdc++.h>

int main()
{
  //freopen("pairup.in", "r", stdin);
  //freopen("pairup.out", "w", stdout);
  int n;
  std::cin >> n;
  std::vector<std::pair<int,int>> v;
  for(int i = 0; i < n; i++)
  {
    int amount, value;
    std::cin >> amount >> value;
    v.push_back({amount,value});
  }
  std::sort(v.begin(), v.end());

  int answer = 0, left = 0, right = n-1;
  while(left <= right)
  {
    int minimum = std::min(v[left].second,v[right].second);
    answer = std::max(answer,v[left].first+v[right].first);

    if(left==right) minimum /= 2;

    v[left].second -= minimum;
    v[right].second -= minimum;

    if(v[left].second==0) left++;
    if(v[right].second==0) right--;
  }

}
