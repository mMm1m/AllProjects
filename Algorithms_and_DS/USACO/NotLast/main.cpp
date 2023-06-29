#include <bits/stdc++.h>
constexpr int COW_NUM = 7;
int main() {
  freopen("notlast.in", "w", stdin);
  freopen("notlast.out", "r", stdout);
  int N;
  std::cin >> N;
  std::map<std::string, int> raw;
  for (int i = 0; i < N; i++) {
    std::string a;
    int b;
    std::cin >> a >> b;
    raw[a] += b;
  }
  std::vector<std::pair<int, std::string>> cows;
  for (std::pair<std::string, int> t : raw) {
    cows.push_back({t.second, t.first});
  }
  sort(cows.begin(), cows.end());
  int ind = 0;
  if (cows.size() == COW_NUM) {
    while (ind < cows.size() && cows[ind].first == cows[0].first) {
      ind++;
    }
  }
  if (ind < cows.size()
      && (ind + 1 == cows.size() ||
          cows[ind].first != cows[ind + 1].first)) {
    std::cout << cows[ind].second << "\n";
  } else {
    std::cout << "Tie" << "\n";
  }
}