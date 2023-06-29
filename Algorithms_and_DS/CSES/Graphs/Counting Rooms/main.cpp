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

int main(){
  int n,m;
  std::cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char c; std::cin >> c;
      vis[i][j] = (c == '#');
    }
  }
  int count = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!vis[i][j]){
        dfs(i, j, n, m);
        count++;
      }
    }
  }
  std::cout << count << '\n';
}