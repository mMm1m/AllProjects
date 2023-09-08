#include <bits/stdc++.h>

int find_first(const std::vector<int>& vector, int temp)
{
  int left = 0, right = vector.size()-1;
  while(left < right)
  {
    int mid = (left+right)/2;
    if(temp <= vector[mid])
    {
      right = mid;
    }
    else left = mid+1;
  }
  if(vector[left] == temp) return left+1;
  return -1;
}

int find_second(const std::vector<int>& vector, int temp)
{
  int left = 0, right = vector.size()-1;
  while(left < right)
  {
    int mid = (left+right)/2;
    if(temp >= vector[mid])
    {
      left = mid;
    }
    else right = mid-1;
  }
  if(vector[left] == temp) return left+1;
  return -1;
}

int main()
{
  std::ios::sync_with_stdio(0);
  std::cin.tie();
  int n,m, temp; std::cin >> n;
  std::vector<int> vector(n);
  std::vector<std::pair<int, int>> answer;
  for(int i = 0; i < n; ++i) {std::cin >> temp; vector[i] = temp;}
  std::cin >> m;
  for(int i = 0; i < m; ++i)
  {
    std::cin >> temp;
    answer.push_back(std::make_pair(find_first(vector, temp), find_second(vector, temp)));
  }
  for(auto& a : answer)
    std::cout << a.first << " " << a.second << '\n';
}
