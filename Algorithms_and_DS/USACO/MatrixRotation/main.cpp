#include <bits/stdc++.h>

void rotation(std::vector<std::vector<int>>& v)
{
  int a = v[0][0], b = v[0][1], c = v[1][1], d = v[1][0];
  v[0][1]=a; v[1][1]=b; v[1][0] = c; v[0][0] = d;
}

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    std::vector<std::vector<int>> v(2,std::vector<int>(2));
    int minimum = 1e9, maximum = -1e9;
    for(int i = 0; i < 2; i++)
    {
      for(int j = 0; j < 2; j++)
      {
        std::cin >> v[i][j];
        v[i][j] < minimum ? minimum = v[i][j] : minimum = minimum;
        v[i][j] > maximum ? maximum = v[i][j] : maximum = maximum;
      }
    }
    bool flag = false;
      for(int j = 0; j < 4; j++) {
        if (v[0][0] == minimum && v[1][1] == maximum) {
          flag = true;
          break;
        }
        rotation(v);
      }
    if(flag) std::cout << "YES" << '\n';
    else std::cout << "NO" << '\n';
  }
}
