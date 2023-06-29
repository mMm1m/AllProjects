#include <bits/stdc++.h>

int main()
{
  int matches, scores, conceded;
  std::cin >> matches >> scores >> conceded;
  if(scores+conceded==matches)
  {
    std::cout << 0 << '\n';
    while(scores>0) std::cout << 1 << ":" << 0 << '\n';
    while(conceded>0) std::cout << 0 << ":" << 0 << '\n';
  }
  else if(scores+conceded>matches)
  {
    if(matches==1&&scores==conceded)
    {
      std::cout << 1 << '\n';
    }
    else std::cout << 0 << '\n';
    while((conceded!=0||scores!=0)&&matches>1)
    {
      if(conceded!=0&&scores!=0&&matches>1)
      {
        std::cout << 1 << ":" << 0 << '\n'; --scores;
        std::cout << 0 << ":" << 1 << '\n'; --conceded;
        matches-=2;
      }
      if(conceded==0&&scores!=0&&matches>0)
      {
        std::cout << 1 << ":" << 0 << '\n'; --scores;
        --matches;
      }
      if(conceded!=0&&scores==0&&matches>0)
      {
        std::cout << 0 << ":" << 1 << '\n'; --conceded;
        --matches;
      }
    }
    std::cout << scores << ":" << conceded << '\n';
  }
  else
  {
    std::cout << matches-scores-conceded << '\n';
    while((conceded!=0||scores!=0)&&matches>1)
    {
      if(conceded!=0&&scores!=0&&matches>1)
      {
        std::cout << 1 << ":" << 0 << '\n'; --scores;
        std::cout << 0 << ":" << 1 << '\n'; --conceded;
        matches-=2;
      }
      if(conceded==0&&scores!=0&&matches>0)
      {
        std::cout << 1 << ":" << 0 << '\n'; --scores;
        --matches;
      }
      if(conceded!=0&&scores==0&&matches>0)
      {
        std::cout << 0 << ":" << 1 << '\n'; --conceded;
        --matches;
      }
    }
    for(int i = 0; i < matches-scores-conceded; ++i)
      std::cout << 0 << ":" << 0 << '\n';
  }
}
