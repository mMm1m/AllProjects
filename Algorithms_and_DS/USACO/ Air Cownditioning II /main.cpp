#include <bits/stdc++.h>

int answer = 1e9;

std::vector<std::pair<int,int>> cow_interval, conditioner_interval;
std::vector<int> cow_comfort, conditioner_cold, conditioner_cost;

int check(std::string str)
{
  std::vector<int> v(101);
  for(int i = 1; i <= 100; ++i)
  {
    for(int j = 0; j < conditioner_interval.size(); ++j)
    {
      if(str[j]=='1' && i<=conditioner_interval[j].second && i>=conditioner_interval[j].first)
      {
        v[i]+=conditioner_cold[j];
      }
    }
  }

  bool works = true;
  for (int i = 0; i < cow_interval.size(); i++) {
    for (int j = cow_interval[i].first; j <= cow_interval[i].second; j++) {
      if (v[j] < cow_comfort[i]) works = false;
    }
  }
  int price = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '1')
      price += conditioner_cost[i];
  }
  if (works) return price;
  return 1e9;
}

void create(std::string str, int k)
{
  if(str.size()==k)
    answer=std::min(answer,check(str));
  else
  {
    create(str+"1",k);
    create(str+"0",k);
  }
}

int main()
{
  int n,m;std::cin >> n >> m;
  for(int i = 0; i < n; ++i)
  {
    int start, end, comfort; std::cin >> start >> end >> comfort;
    cow_interval.push_back(std::make_pair(start,end));
    cow_comfort.push_back(comfort);
  }
  for(int i = 0; i < m; ++i)
  {
    int start, end, cold,cost; std::cin >> start >> end >> cold >> cost;
    conditioner_interval.push_back(std::make_pair(start,end));
    conditioner_cold.push_back(cold); conditioner_cost.push_back(cost);
  }
  create("",m);
  std::cout << answer;
}
