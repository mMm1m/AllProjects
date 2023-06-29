#include <bits/stdc++.h>

int main()
{
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  int n;
  std::cin >> n;
  std::vector<int> scissors(n+1,0), hoop(n+1,0), paper(n+1,0);

  for(int i = 1; i < n+1; i++)
  {
    scissors[i] = scissors[i-1];
    hoop[i] = hoop[i-1];
    paper[i] = paper[i-1];

    char symbol;
    std::cin >> symbol;
    switch(symbol)
    {
      case 'P':
        scissors[i]++;
        break;
      case 'S':
        hoop[i]++;
        break;
      case 'H':
        paper[i]++;
        break;
    }
  }

  /*for(auto& a : scissors)
    std::cout << a << " ";
  std::cout << "\n";

  for(auto& a : paper)
    std::cout << a << " ";
  std::cout << "\n";

  for(auto& a : hoop)
    std::cout << a << " ";
  std::cout << "\n";*/


  int answer = 0;
  for(int i = 1; i < n+1; i++)
  {
    int before = std::max({scissors[i],hoop[i],paper[i]});
    int after = std::max({scissors[n]-scissors[i],paper[n]-paper[i],
                          hoop[n]-hoop[i]});
    answer = std::max(answer, before+after);
  }
  std::cout << answer;

}
