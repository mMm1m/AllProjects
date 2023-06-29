#include <bits/stdc++.h>
using vp = std::vector<std::pair<int,int>>;
using ms = std::multiset<std::pair<int,int>>;

int main()
{
  freopen("reduce.in","r",stdin);
  freopen("reduce.out","w",stdout);
  int n; std::cin >> n;
  ms x_set, y_set;
  for(int i = 0; i < n; ++i)
  {
    int x,y; std::cin >> x >> y;
    x_set.insert({x,y});
    y_set.insert({y,x});
  }
  int ans = 1e9;
  for(int i = 0; i <= 3; ++i) // x_start
  {
    for(int j = 0; j <= 3; ++j) // x_end
    {
      for(int k = 0; k <= 3; ++k) // y_start
      {
        for(int l = 0; l <= 3; ++l) // y_end
        {
          vp vector;
          if(i+j+k+l==3)
          {
            for(int m = 0; m < i; ++m)
            {
              auto it = *x_set.begin();
              vector.push_back(it);
              x_set.erase(x_set.find(it));
              y_set.erase(y_set.find({it.second,it.first}));
            }
            for(int m = 0; m < j; ++m)
            {
              auto it = *(--x_set.end());
              vector.push_back(it);
              x_set.erase(x_set.find(it));
              y_set.erase(y_set.find({it.second,it.first}));
            }
            for(int m = 0; m < k; ++m)
            {
              auto it = *y_set.begin();
              vector.push_back({it.second,it.first});
              y_set.erase(y_set.find(it));
              x_set.erase(x_set.find({it.second,it.first}));
            }
            for(int m = 0; m < l; ++m)
            {
              auto it = *(--y_set.end());
              vector.push_back({it.second,it.first});
              y_set.erase(y_set.find(it));
              x_set.erase(x_set.find({it.second,it.first}));
            }
          }
          ans = std::min(ans,((*(--x_set.end())).first-(*x_set.begin()).first)
          *((*(--y_set.end())).first-(*y_set.begin()).first));
          for(auto& a : vector)
          {
            x_set.insert(a);
            y_set.insert(std::make_pair(a.second,a.first));
          }
        }
      }
    }
  }
  std::cout << ans;
}
