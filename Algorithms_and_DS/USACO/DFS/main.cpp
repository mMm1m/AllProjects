#include <bits/stdc++.h>

std::vector<std::pair<int,int>> v = {{1,0}, {-1,0}, {0,1}, {0,-1}};
bool vis[1001][1001];

void dfs(int x, int y, int n, int m){
  vis[x][y] = true;
  for(auto& a : v){
    int dx = x+a.first, dy = y+a.second;
    if(0 <= dx && dx < n && 0 <= dy && dy < m && !vis[dx][dy])
      dfs(dx, dy, n, m);
  }
}