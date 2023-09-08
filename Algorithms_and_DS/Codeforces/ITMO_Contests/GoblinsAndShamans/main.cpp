#include <bits/stdc++.h>

int main()
{
  char c;
  int n, temp; std::cin >> n;
  std::string string;
  std::deque<int> ordinary_goblins, privelegue_goblins;
  for(int i = 0; i < n; ++i)
  {
    std::cin >> c;
    if(c == '+') {
      std::cin >> temp;
      privelegue_goblins.push_back(temp);
    }
    else if(c == '-')
    {
      std::cout << ordinary_goblins.front() << '\n';
      ordinary_goblins.pop_front();
    }
    else {
      std::cin >> temp;
      privelegue_goblins.push_front(temp);
    }
    if(ordinary_goblins.size() < privelegue_goblins.size())
    {
      ordinary_goblins.push_back(privelegue_goblins.front());
      privelegue_goblins.pop_front();
    }
  }
}
