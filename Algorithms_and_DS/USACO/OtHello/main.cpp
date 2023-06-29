#include <bits/stdc++.h>

std::vector<std::pair<int, int>> vector;

std::vector<std::pair<int, int>> allLegalMoves(char (&board)[12][12], char sigma_letter)
{
  vector.clear();
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i - 1][j - 1] && sigma_letter == board[i - 2][j - 2]))
      {
        vector.push_back({i - 2, j - 2});

      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i - 1][j] && sigma_letter == board[i - 2][j]))
      {
        vector.push_back({i - 2, j});
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i - 1][j + 1] && sigma_letter == board[i - 2][j + 2]))
      {
        vector.push_back({i - 2, j + 2});
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i][j + 1] && sigma_letter == board[i][j + 2]))
      {
        vector.push_back({i, j + 2});
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i + 1][j + 1] && sigma_letter == board[i + 2][j + 2]))
      {
        vector.push_back({i + 2, j + 2});
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i + 1][j] && sigma_letter == board[i + 2][j]))
      {
        vector.push_back({i + 2, j});
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i + 1][j - 1] && sigma_letter == board[i + 2][j - 2]))
      {
        vector.push_back({i + 2, j - 2});
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i][j - 1] && sigma_letter == board[i][j - 2]))
      {
        vector.push_back({i, j - 2});
      }
    }
  }
  return vector;
}

void modify(char (&board)[12][12], char sigma_letter)
{
  if(sigma_letter == 'W') sigma_letter = 'B';
  else if(sigma_letter == 'B') sigma_letter = 'W';

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i - 1][j - 1] && sigma_letter == board[i - 2][j - 2]))
      {
        // change board[i - 1][j - 1];
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i - 1][j] && sigma_letter == board[i - 2][j]))
      {
        // change board[i - 1][j];
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i - 1][j + 1] && sigma_letter == board[i - 2][j + 2]))
      {
        // change board[i - 1][j + 1];
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i][j + 1] && sigma_letter == board[i][j + 2]))
      {
        // change board[i][j + 1];
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i + 1][j + 1] && sigma_letter == board[i + 2][j + 2]))
      {
        // change board[i + 1][j + 1];
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i + 1][j] && sigma_letter == board[i + 2][j]))
      {
        // change board[i + 1][j];
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i + 1][j - 1] && sigma_letter == board[i + 2][j - 2]))
      {
        // change board[i + 1][j - 1];
      }
      if ((board[i][j] == sigma_letter) && (sigma_letter != board[i][j - 1] && sigma_letter == board[i][j - 2]))
      {
        // change board[i][j - 1];
      }
    }
  }

  int white = 0, black = 0;
  for(int i = 2; i < 10; i++)
  {
    for(int j = 2; j < 10; j++)
    {
      if(board[i][j] == 'W')
      {
        ++white;
      }
      else if(board[i][j] == 'B')
      {
        ++black;
      }
    }
  }
  std::cout << "Black - " << black << " White - " << white << '\n';
}

int main()
{
  char board[12][12];
  int tests;
  char letter;
  std::cin >> tests;
  while(tests--)
  {
    std::vector<std::pair<int,int>> temp;

    for(int i = 0; i < 12; i++)
    {
      for(int j = 0; j < 12; j++)
      {
        board[i][j] = '.';
      }
    }

      for (int i = 2; i < 10; i++)
      {
        for (int j = 2; j < 10; j++)
        {
          std::cin >> board[i][j];
        }
      }

      std::cin >> letter;
      if(letter == 'Q')
      {
        continue;
      }
      else
      {
        char sigma_letter;
        if (letter == 'B' || letter == 'W')
        {
          sigma_letter = letter;
          temp = allLegalMoves(board, letter);
        }
        else if (letter == 'L')
        {
          for (auto& a: temp)
          {
            std::cout << '(' << a.first << ',' << a.second << ')' << " ";
          }
          std::cout << '\n';
        }
        else if (letter == 'M')
        {
          int row, column;
          std::cin >> row >> column;
          board[row][column] = sigma_letter;
          modify(board, sigma_letter);
        }
      }
  }
}
