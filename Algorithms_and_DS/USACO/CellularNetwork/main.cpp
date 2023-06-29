#include <bits/stdc++.h>

int main()
{
  int l, t;
  std::cin >> l >> t;
  std::vector< int > locality, tower;
  for (int i = 0; i < l; i++) {
    int value;
    std::cin >> value;
    locality.push_back(value);
  }

  for (int i = 0; i < t; i++) {
    int value;
    std::cin >> value;
    tower.push_back(value);
  }

  int pointer = 0;
  std::vector< int > answer_(1e5, 2*1e9+7);
  for (int i = 0; i < l; i++) {
    while (pointer < t - 1 && tower[pointer + 1] <= locality[i]) pointer++;
    answer_[i] = std::min(std::abs(tower[pointer] - locality[i]), answer_[i]);
  }
  pointer = t - 1;
  for (int i = l - 1; i >= 0; i--) {
    while (pointer > 0 && tower[pointer - 1] >= locality[i]) pointer--;
    answer_[i] = std::min(std::abs(tower[pointer] - locality[i]), answer_[i]);
  }

  int ans = 0;
  for(int i = 0;i < l; i++) ans = std::max(ans,answer_[i]);
  std::cout << ans;
}