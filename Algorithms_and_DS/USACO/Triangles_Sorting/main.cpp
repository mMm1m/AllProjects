#include <bits/stdc++.h>

const int MOD = 1e9+7;

int main()
{
  freopen("triangles.in", "r", stdin );
  freopen("triangles.out", "w", stdout);
  int n;
  std::cin >> n;
  int x[n];
  int y[n];
  for(int i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }

  int answer = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      for(int k = 0; k < n; k++)
      {
        if(y[i] == y[j] && x[i] == x[k]) {
          int square = std::abs((y[k] - y[i]) * (x[j] - x[i]));
          answer += square;
        }
      }
    }
  }
  std::cout << answer%(MOD);
  return 0;
}
