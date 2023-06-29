#include <bits/stdc++.h>

std::multiset<int> set[2];
int count = 0;
std::vector<int> pos(2001);
void recursion(int day, int amount)
{
  if(day==6)
  {
    count += 1-pos[amount];
    pos[amount]=1;
    return;
  }
  std::vector<int> v;
  int p = (day%2);
  auto it = set[p].begin();
  while(it != set[p].end())
  {
    v.push_back(*it);
    ++it;
  }
  for(int i = 0; i < v.size(); ++i)
  {
    set[p].erase(set[p].find(v[i]));
    set[1-p].insert(v[i]);
    if(p==0)
      recursion(day+1, amount-v[i]);
    else
      recursion(day+1, amount+v[i]);
    set[1-p].erase(set[1-p].find(v[i]));
    set[p].insert(v[i]);
  }
}

int main()
{
  freopen("backforth.in", "r", stdin);
  freopen("backforth.out", "w", stdout);
  for(int i = 0; i < 2; ++i)
  {
    for(int j = 0; j < 10; ++j)
    {
      int val; std::cin >> val;
      set[i].insert(val);
    }
  }
  recursion(2,1000);
  std::cout << count;
}
