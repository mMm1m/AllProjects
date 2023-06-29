#include <bits/stdc++.h>
using ll = long long;
const ll MAX = 2e5+5;

std::vector<std::vector<ll>> adjacent_list(MAX);
bool visited[MAX];
std::vector<int> b;

void dfs(ll city)
{
  visited[city] = true;
  for(auto& a : adjacent_list[city])
    if(!visited[a]) dfs(a);
}

int main()
{
  int cities, bridges;
  std::cin >> cities >> bridges;
  for(int i = 0; i < bridges; i++)
  {
    int first, second;
    std::cin >> first >> second;
    adjacent_list[first].push_back(second); adjacent_list[second].push_back(first);
  }
  for(int i = 1; i <= cities; i++)
    if(!visited[i]) { b.push_back(i); dfs(i); }
  std::cout << b.size()-1 << '\n';
  for (int i = 0; i < b.size() - 1; i++) {
    std::cout << b[i] << " " << b[i + 1] << '\n';
  }
}