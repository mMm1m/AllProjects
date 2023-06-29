#include <bits/stdc++.h>

int main()
{
  int row, column, cases = 0;
  char board[20][20];
  while(scanf("%d %d", &row, &column) == 2)
  {
  std::cin >> row >> column;
    for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++)
        std::cin >> board[i][j];
    int num[20][20] = {}, cnt = 0;
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        if (i - 1 < 0 || j - 1 < 0 || board[i - 1][j] == '*' || board[i][j - 1] == '*')
          if (board[i][j] != '*')
            num[i][j] = ++cnt;
      }
    }

    std::vector<std::pair<int, std::string>> across, down;

    for(int i = 0; i < row; i++)
    {
      for(int j = 0; j < column; j++)
      {
        if(num[i][j] != 0)
        {
          std::string str = "";
          int curr_i = i, curr_j = j;
          while(curr_i < row || num[curr_i][j] != 0)
          {
            str += board[curr_i][j];
          }
          if(!str.empty())
          {
            down.push_back({num[i][j], str});
            str.clear();
          }
          while(curr_j < j || num[i][curr_j] != 0)
          {
            str += board[i][curr_j];
          }
          if(!str.empty())
          {
            across.push_back({num[i][j], str});
            str.clear();
          }
        }
      }
    }
    std::cout << "puzzle #" << ++cases << ":\n";
    std::cout << "Across" << '\n';
    for(auto& a : across)
      std::cout << a.first << "." << a.second << '\n';
    std::cout << "Down" << '\n';
  for(auto& a : down)
    std::cout << a.first << "." << a.second << '\n';
  }
}
