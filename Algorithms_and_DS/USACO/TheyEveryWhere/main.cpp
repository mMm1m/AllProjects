#include <bits/stdc++.h>

int main()
{
  int n; std::unordered_set<char> set;
  std::cin >> n;
  std::vector<char> p(n);
  for(int i = 0; i < n; i++)
  {
    std::cin >> p[i];
    set.insert(p[i]);
  }

  std::unordered_map<char, int> map;
  int left = 0, answer = 1e9;
  for(int right = 0; right < n; right++)
  {
    map[p[right]]++;
    while(right-left >= 1 && map.count(map[p[left]]) &&
    map[p[left]] > 1)
    {
      map[p[left]]--;
      left++;
    }
    if(map.size()==set.size())
      answer = std::min(answer, right - left + 1);
  }

  std::cout << answer;
}
