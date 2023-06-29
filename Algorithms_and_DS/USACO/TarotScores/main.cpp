#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  double score;
  int oudlers;
  char points[] = {56,51,41,36};

  for(int i = 0; i < t; i++)
  {
    int m;
    score = oudlers = 0;
    std::cin >> m;
    std::cin.ignore();
    std::string string;
    for(int j = 0; j < m; j++)
    {
      getline(std::cin, string);
      if(string.find("king") != std::string::npos || string == "fool" || string == "twenty-one of trumps" || string == "one of trumps")
      {
        ++oudlers;
        score += 4.5;
      }
      else if(string.find("queen") != std::string::npos)
      {
        score += 3.5;
      }
      else if(string.find("knight") != std::string::npos)
      {
        score += 2.5;
      }
      else if(string.find("jack") != std::string::npos)
      {
        score += 1.5;
      }
      else
      {
        score += 0.5;
      }
    }
    std::cout << "Hand #" << ++i << '\n';
    if(points[oudlers] > score)
    {
      std::cout << "Game lost by " << points[oudlers] - score << " point(s)." << '\n';
    }
    else
    {
      std::cout << "Game win by " << points[oudlers] - score << " point(s).";
    }
  }
}
