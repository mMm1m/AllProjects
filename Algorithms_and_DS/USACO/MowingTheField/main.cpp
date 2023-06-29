#include <bits/stdc++.h>

void command(char symbol, int value, int& curr_i, int& curr_j, int count, int* arr[21])
{
  if(symbol == 'N')
  {
    for(int i = curr_i; i >= curr_i - value; i++) {
      for (int j = curr_j; j <= curr_j;) {
        if(arr[i][j] == 1)
          std::cout << count;
        count++;
      }
    }
      curr_i -= value;
  }
  if(symbol == 'S')
  {
    for(int i = curr_i; i <= curr_i + value; i++) {
      for (int j = curr_j; j <= curr_j;) {
        if(arr[i][j] == 1)
          std::cout << count;
        count++;
      }
    }
    curr_i += value;
  }
  if(symbol == 'E')
  {
    for(int i = curr_i; i <= curr_i;) {
      for (int j = curr_j; j <= curr_j + value; j++) {
        if(arr[i][j] == 1)
          std::cout << count;
        count++;
      }
    }
    curr_j += value;
  }
  if(symbol == 'W')
  {
    for(int i = curr_i; i <= curr_i;) {
      for (int j = curr_j; j >= curr_j - value; j++) {
        if(arr[i][j] == 1)
          std::cout << count;
        count++;
      }
    }
    curr_j -= value;
  }
}

int main()
{
  //freopen("mowing.in", "r", stdin);
  //freopen("mowing.out", "w", stdout);
  int n;
  std::cin >> n;
  int arr[21][21];
  for(int i = 0; i < 20; i++)
    for (int j = 0; j < 20; j++)
      arr[i][j] = 0;
  int start_row = 10, start_column = 10, count = 0;
  for(int i = 0; i < n; i++)
  {
    char symbol; int step;
    std::cin >> symbol >> step;
    command(symbol, step, start_row, start_column, arr);
  }

  return 0;
}
