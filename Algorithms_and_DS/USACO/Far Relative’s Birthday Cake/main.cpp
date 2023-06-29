#include <bits/stdc++.h>

int C(int n, int k)
{
  if (k==0 || k==n)
    return 1;
  else
    return C(n-1,k-1)+C(n-1,k);
}

int main()
{
  int n; std::cin >> n;
  char grid[n][n];
  for(int i = 0; i < n; ++i)
    for(int j=  0; j < n; ++j)
      std::cin >> grid[i][j];
  std::vector<std::pair<int,std::vector<int>>> row(n), column(n);
  for(int i = 0; i < n; ++i)
  {
    for(int j =  0; j < n; ++j)
      if(grid[i][j]=='C') {row[i].second.push_back(j);column[j].second.push_back(i);}
  }
  int count = 0;
  for(auto& a : row)
  {
    int s = a.second.size();
    if(s>=2)
    {
      int f = C(s,2);
      count += f;
    }
  }
  for(auto& a : column)
  {
    int s = a.second.size();
    if(s>=2)
    {
      int f = C(s,2);
      count += f;
    }
  }
  std::cout << count << '\n';
}
