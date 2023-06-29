#include <bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> guards(n);
  for(int i = 0; i < n; i++)
    std::cin >> guards[i].first >> guards[i].second;

  std::sort(guards.begin(), guards.end());

  int total = 0, left_ = 0, right_ = 0;
  for(int i = 0; i < n; i++)
  {
    if(guards[i].second > right_)
    {
      left_ = std::max(right_, guards[i].first);
      total += guards[i].second - left_;
      right_ = guards[i].second;
    }
  }

  int min_alone_time = total;
  right_ = 0;
  for (int i = 0; i < n; i++) {
    int curr_res = std::min(guards[i + 1].first, guards[i].second) - std::max(guards[i].first, right_);
    min_alone_time = std::min(min_alone_time, curr_res);
    right_ = std::max(right_, guards[i].second);
  }


  std::cout << total - std::max(0, min_alone_time);

}
