#include <bits/stdc++.h>

char move[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};

bool fight(char first_fighter, char second_fighter)
{
  if(first_fighter == 'R')
  {
    if(second_fighter == 'S')
      return true;
    return false;
  }
  if(first_fighter == 'P')
  {
    if(second_fighter == 'R')
      return true;
    return false;
  }

  if(second_fighter == 'P')
    return true;
  return false;
}

int main()
{
  int row, column, tests;
  std::cin >> tests;
  while(tests--)
  {
    int n;
    std::cin >> row >> column >> n;
    std::vector<std::vector<char>> board(row, std::vector<char>(column));
    for(int i = 0; i < row; i++)
    {
      for(int j = 0; j < column; j++)
      {
        std::cin >> board[i][j];
      }
    }

    std::vector<std::vector<char>> temp(board);

    for(int h = 0; h < n; h++)
    {
      for(int i = 0; i < row; i++)
      {
        for(int j = 0; j < column; j++)
        {
          for(int k = 0; k < 4; k++)
          {
            int x = i + move[k][0];
            int y = j + move[k][1];
            if (x < row && y < column && x > -1 && y > -1)
            {
              if (fight(temp[i][j], temp[x][y]))
                board[x][y] = temp[i][j];
            }
          }
        }
      }
    }

    for(int i = 0; i < row; i++)
    {
      for(int j = 0; j < column; j++)
      {
        std::cout << board[i][j];
      }
      std::cout << '\n';
    }

  }
}
