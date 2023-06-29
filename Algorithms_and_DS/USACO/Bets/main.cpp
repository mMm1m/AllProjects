#include <bits/stdc++.h>

struct Biatlonist
{
  int left, right, time, coins;
  Biatlonist(int l, int r, int t, int c)
  {
    left = l;
    right = r;
    time = t;
    coins = c;
  }
};

int main()
{
  int n,m;
  std::cin >> n >> m;
  std::vector<Biatlonist> v;
  for(int i = 0; i < m; i++)
  {
    int a,b,c,d;
    std::cin >> a >> b >> c >> d;
    v.push_back(Biatlonist(a,b,c,d));
  }
  int sum = 0;
  for(int i = 1; i <= n; i++)
  {
    int curr = 0, time = 1000000;
    for(int j = 0; j < m; j++)
    {
      if(v[j].left<=i && v[j].right>=i)
      {
        if(v[j].time<time)
        {
          time = v[j].time;
          curr = v[j].coins;
        }
        else if(v[j].time==time && v[j].coins>curr)
          curr = v[j].coins;
      }
    }
    sum += curr;
  }
  std::cout << sum;
}
