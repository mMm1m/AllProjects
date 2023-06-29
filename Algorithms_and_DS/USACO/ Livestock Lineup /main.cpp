#include <bits/stdc++.h>
int n;
std::vector<std::string> a_, b_, cows;
int find_pos(std::string str)
{
  for(int i = 0; i < 8; ++i)
    if(cows[i]==str) return i;
  return -1;
}

bool true_expr()
{
  for(int i = 0; i < n; ++i)
    if(std::abs(find_pos(a_[i])-find_pos(b_[i]))!=1) return false;
  return true;
}

int main()
{
  freopen("lineup.in","r",stdin);
  freopen("lineup.out","w",stdout);
  std::cin >> n;
  cows.push_back("Beatrice");
  cows.push_back("Belinda");
  cows.push_back("Bella");
  cows.push_back("Bessie");
  cows.push_back("Betsy");
  cows.push_back("Blue");
  cows.push_back("Buttercup");
  cows.push_back("Sue");
  for(int i = 0; i < n; ++i)
  {
    std::string A,b,c,d,e,F; std::cin >> A >> b >> c >> d >> e >> F;
    a_.push_back(A); b_.push_back(F);
  }
  do
  {
    if(true_expr())
    {
      for(int i = 0; i < 8; ++i) std::cout << cows[i] << '\n';
      break;
    }
  } while(std::next_permutation(cows.begin(), cows.end()));
}
