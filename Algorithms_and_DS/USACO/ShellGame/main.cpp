#include <bits/stdc++.h>

int main()
{
  freopen("shell.in","r",stdin);
  freopen("shell.out","w",stdout);
  int n, ans = 0; std::cin >> n;
  int v[n][3];
  for(int i = 0; i < n; ++i)
    for(int j = 0;  j < 3; ++j)
      std::cin >> v[i][j];

  for(int i = 1; i <= 3; ++i)
  {
    int curr_pos = i, curr = 0;
    for(int j = 0; j < n; ++j)
    {
      if(curr_pos==v[j][0])
        curr_pos = v[j][1];
      else if(curr_pos==v[j][1])
        curr_pos = v[j][0];
      if(curr_pos==v[j][2])
        ++curr;
    }
    ans = std::max(ans, curr);
  }
  std::cout << ans;
}