#include <bits/stdc++.h>

 const int constanta = 1e3;
 std::vector<std::vector<int>> forest(constanta+1, std::vector<int>(constanta+1, 0));
std::vector<std::vector<int>> prefix_tree(constanta+1, std::vector<int>(constanta+1, 0));

int main()
{
  int n, q;
  std::cin >> n >> q;
  for(int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      char a;
      std::cin >> a;
      a == '*' ? forest[i+1][j+1] = 1 : 0;
    }
  }

  // create prefix
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      prefix_tree[i+1][j+1] = forest[i+1][j+1] + prefix_tree[i+1][j] + prefix_tree[i][j+1] - prefix_tree[i][j];

  // out answer
  for(int i = 0; i < q; i++) {
      int x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      std::cout << prefix_tree[x2][y2] - prefix_tree[x1-1][y2] - prefix_tree[x2][y1-1] + prefix_tree[x1-1][y1-1] << "\n";
  }


  /*for(int i = 0; i <= n; i++)
  {
    for(int j = 0; j <= n; j++)
    {
      std::cout << forest[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  for(int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      std::cout << prefix_tree[i][j] << " ";
    }
    std::cout << "\n";
  }*/


}
