#include <bits/stdc++.h>
int main()
{
  //ifstream cin("lazy.in");
  //ofstream cout("lazy.out");
  int n, k;
  std::cin >> n >> k;
  int ans = 0;
  int prefix[n][n + 1], a[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      std::cin >> a[i][j];

  for (int i = 0; i < n; i++) {
    prefix[i][0] = 0;
    for (int j = 0; j < n; j++)
      prefix[i][j + 1] = prefix[i][j] + a[i][j];
  }

  int answer = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      // high-to-low
      int sum = 0, current_row = i, right = j+k+1, left = j-k+1;
      while(current_row >= 0 && left <= right)
      {
        sum += prefix[current_row][std::min(n,right)] - prefix[current_row][std::max(1, left)-1];
        current_row--;
        right--;
        left++;
      }

      current_row = i+1; left = j-k+2; right = j+k;
      // low-to-high
      while(current_row >= 0 && left <= right)
      {
        sum += prefix[current_row][std::min(n,right)] - prefix[current_row][std::max(1, left)-1];
        current_row++;
        right--;
        left++;
      }

      answer = std::max(answer, sum);
    }
  }

  /*for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cout << a[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\n";

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      std::cout << prefix[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\n";*/

  std::cout << answer;
}