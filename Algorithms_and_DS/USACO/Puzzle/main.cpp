#include <bits/stdc++.h>

bool correct_string(std::string str)
{
  str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
  bool flag = true;
  for(int i = 1; i < str.size(); i++)
    if(str[i-1] >= str[i]) flag = false;
  return flag;
}

void fill(char (&board)[5][5], std::string s)
{
  int k = 0;
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      board[i][j] = s[k];
      ++k;
    }
  }
}

void moves(char (&board)[5][5])
{
  int row = 0, column = 0;
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      if(board[i][j]== ' ') row = i; column = j;
    }
  }
  // first move - above
  std::swap(board[row-1][column], board[row][column]);
  // second move - right
  std::swap(board[row-1][column+1],board[row-1][column]);
  // third move - right
  std::swap(board[row-1][column+2],board[row-1][column+1]);
  // forth move - below
  std::swap(board[row][column+2],board[row-1][column+2]);
  // fifth move - below
  std::swap(board[row+1][column+2],board[row][column+2]);
  // sixth move - left
  std::swap(board[row+1][column+1],board[row-1][column+2]);
}

void print(char (&board)[5][5])
{
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      std::cout << board[i][j] << " ";
    }
    std::cout << '\n';
  }
}

int main()
{
  std::string string;
  int count = 0, count_of_puzzles = 0;
  std::string str = "";
  char board[5][5];
  while(getline(std::cin, string), string != "Z")
  {
    if(string.size()==5)
    {
      for(int i = 0; i < string.size(); i++)
        str += string[i];
      ++count;
      if(count==5)
      {
        if(str.size()==25 && str.find(' ')) {
          if (!correct_string(str))
          {
            fill(board, str);
            moves(board);
            std::cout << "Puzzle #" << ++count_of_puzzles << ":\n";
            print(board);
          }
          else
          {
            std::cout << "This puzzle has no final configuration." << '\n';
          }
        }
        str.clear();
        count = 0;
      }
    }
    else
    {
      str.clear();
      count = 0;
      continue;
    }
  }
}
