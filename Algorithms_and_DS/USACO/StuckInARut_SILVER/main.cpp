#include <bits/stdc++.h>
using pair = std::pair<int,int>;
using ll = long long;

struct Cow
{
  ll cow_num; pair p;
  Cow(pair pair_, ll cow_)
  {
    p = pair_;
    cow_num = cow_;
  }
};

int main()
{
  std::vector<Cow> east, north;
  int n; std::cin >> n;
  for(int i = 0; i < n; ++i)
  {
    char str; int x,y;
    std::cin >> str >> x >> y;
    if(str=='E')
      east.push_back(Cow(std::make_pair(x,y),i));
    else
      north.push_back(Cow(std::make_pair(x,y),i));
  }
  std::sort(east.begin(),east.end(),[](const Cow& p1, const Cow& p2){
    return p1.p.second < p2.p.second;
  });
  std::sort(north.begin(),north.end(),[](const Cow& p1, const Cow& p2){
    return p1.p.first < p2.p.first;
  });
  std::vector<int> how_much_cows_stop(2005,0);
  bool f_vector[2005]; std::fill(f_vector,f_vector+n,false);
  for(auto& e_ : east)
  {
    for(auto& n_ : north)
    {
      if(e_.p.first <= n_.p.first && e_.p.second >= n_.p.second
      && !f_vector[e_.cow_num] && !f_vector[n_.cow_num])
      {
        ll x_diff = n_.p.first-e_.p.first, y_diff = e_.p.second-n_.p.second;
        if(x_diff > y_diff)
        {
          f_vector[e_.cow_num]=true;
          how_much_cows_stop[n_.cow_num] += (how_much_cows_stop[e_.cow_num]+1);
        }
        else if(y_diff > x_diff)
        {
          f_vector[n_.cow_num]=true;
          how_much_cows_stop[e_.cow_num] += (how_much_cows_stop[n_.cow_num]+1);
        }
      }
    }
  }
  for(int i = 0; i < n; ++i) std::cout << how_much_cows_stop[i] << '\n';
}
