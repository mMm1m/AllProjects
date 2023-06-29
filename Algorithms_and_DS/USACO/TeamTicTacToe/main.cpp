#include <bits/stdc++.h>

const int constanta = 3;

std::vector<std::string> board(constanta);
std::set<std::set<char>> winners[constanta + 1];
void insert(std::vector<std::pair<int, int>> coordinates) {
  std::set<char> contain_cows;
  for (const std::pair<int, int>& p: coordinates) {
    contain_cows.insert(board[p.first][p.second]);
  }
  winners[contain_cows.size()].insert(contain_cows);
}
int main() {
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);
  for (int r = 0; r < constanta; r++) {
    std::cin >> board[r];
  }
  for (int i = 0; i < constanta; i++)
    insert({{i, 0}, {i, 1}, {i, 2}});
  for (int i = 0; i < constanta; i++)
    insert({{0, i}, {1, i}, {2, i}});
  insert({{0, 0}, {1, 1}, {2, 2}});
  insert({{2, 0}, {1, 1}, {0, 2}});
  std::cout << winners[1].size() << "\n";
  std::cout << winners[2].size() << "\n";
}
