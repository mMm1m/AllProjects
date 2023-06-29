/*#include <bits/stdc++.h>

std::multiset< int > set[2];
int answer = 0;
int amount[2001];

void recursion(int i, int j)
{

  if(i == 6)
  {
    answer += 1 - amount[j];
    amount[j] = 1;
    return;
  }

  int indicator = i%2;
  std::vector<int> values;
  for(std::multiset<int>::iterator it = set[indicator].begin(); it != set[indicator].end(); it++)
    values.push_back(*it);

  for(int k = 0; k < values.size(); k++)
  {
    set[indicator].erase(set[indicator].find(values[k]));
    set[1-indicator].insert(values[k]);

    if(indicator==0){recursion(i+1, j-values[k]);}
    else { recursion(i+1,j+values[k]);}

    set[1-indicator].erase(set[1-indicator].find(values[k]));
    set[indicator].insert(values[k]);
  }

}

int main()
{
  freopen("backforth.in","r",stdin);
  freopen("backforth.out","w",stdout);

  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      int value;
      std::cin >> value;
      set[i].insert(value);
    }
  }
  // day and amount of milk
  recursion(2,1000);
  std::cout << answer;
}*/
