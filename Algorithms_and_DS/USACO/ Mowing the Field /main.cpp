#include <bits/stdc++.h>

struct Field
{
  bool grass; int time;
};

int main()
{
  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);
  int n, time_ = 0, curr_x = 1050, curr_y= 1050, ans = 0; std::cin >> n;
  std::vector<std::vector<Field>> field(2*curr_x+1, std::vector<Field>(2*curr_y+1));
  field[curr_x][curr_y].time = 0; field[curr_x][curr_y].grass = true;
  for(int i=0; i < n; ++i)
  {
    char c;  int k; std::cin >> c >> k;
    if(c=='N')
    {
      for(int j = 1; j <= k; ++j)
      {
        --curr_y; ++time_;
        if(field[curr_x][curr_y].grass)
        {
          ans = time_-field[curr_x][curr_y].time;
          std::cout << ans << '\n';
          return 0;
        }
        field[curr_x][curr_y].time = time_;
        field[curr_x][curr_y].grass = true;
      }
    }
    else if(c=='S')
    {
      for(int j = 1; j <= k; ++j)
      {
        ++curr_y; ++time_;
        if(field[curr_x][curr_y].grass)
        {
          ans = time_-field[curr_x][curr_y].time;
          std::cout << ans << '\n';
          return 0;
        }
        field[curr_x][curr_y].time = time_;
        field[curr_x][curr_y].grass = true;
      }
    }
    else if(c=='E')
    {
      for(int j = 1; j <= k; ++j)
      {
        ++curr_x; ++time_;
        if(field[curr_x][curr_y].grass)
        {
          ans = time_-field[curr_x][curr_y].time;
          std::cout << ans << '\n';
          return 0;
        }
        field[curr_x][curr_y].time = time_;
        field[curr_x][curr_y].grass = true;
      }
    }
    else
    {
      for(int j = 1; j <= k; ++j)
      {
        --curr_x; ++time_;
        if(field[curr_x][curr_y].grass)
        {
          ans = time_-field[curr_x][curr_y].time;
          std::cout << ans << '\n';
          return 0;
        }
        field[curr_x][curr_y].time = time_;
        field[curr_x][curr_y].grass = true;
      }
    }
    std::cout << 0 << '\n';
  }
}
