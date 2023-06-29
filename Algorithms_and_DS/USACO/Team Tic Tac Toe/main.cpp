#include <bits/stdc++.h>

int main()
{
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);
  std::vector<std::string> grid(3);
  std::set<std::set<char>> set;
  for(int i = 0; i < 3; ++i) std::cin >> grid[i];
  // rows
  for(int i = 0; i < 3; i++)
  {
    std::set<char> tmp;
    tmp.insert(grid[i][0]); tmp.insert(grid[i][1]); tmp.insert(grid[i][2]);
    set.insert(tmp);
  }
  // columns
  for(int i = 0; i < 3; i++)
  {
    std::set<char> tmp;
    tmp.insert(grid[0][i]); tmp.insert(grid[1][i]); tmp.insert(grid[2][i]);
    set.insert(tmp);
  }
  // cross
  std::set<char> tmp;
  tmp.insert(grid[0][0]); tmp.insert(grid[1][1]); tmp.insert(grid[2][2]);
  set.insert(tmp); tmp.clear();
  tmp.insert(grid[0][2]); tmp.insert(grid[1][1]); tmp.insert(grid[2][0]);
  set.insert(tmp);

  int one = 0, two = 0;
  for(auto it = set.begin(); it != set.end(); ++it)
  {
    if(it->size()==2) ++two;
    if(it->size()==1) ++one;
  }
  std::cout << one << '\n' << two;
}
