#include <bits/stdc++.h>
int n;
std::vector<int> cows;

int max_solution()
{
  return std::max(cows[cows.size()-2]-cows[0],cows[cows.size()-1]-cows[1])-(cows.size()-2);
}

int min_solution()
{
  if(cows[cows.size()-2]-cows[0]==2 && cows[cows.size()-2]-cows[cows.size()-1] > n-2)
    return 2;
  if(cows[cows.size()-2]-cows[0]==2 && cows[1]-cows[0] > n-2)
    return 2;
  int minimum = 0, right = 0;
  for(int left = 0; left < n; left++)
  {
    while(right < n-1 && cows[right+1]-cows[left] <= n-1) right++;
    minimum = std::max(minimum, right-left+1);
  }
  return n-minimum;
}

int main()
{
  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);
  std::cin >> n;
  for(int i = 0;  i < n; i++)
  {
    int val;
    std::cin >> val;
    cows.push_back(val);
  }

  std::sort(cows.begin(), cows.end());

  std::cout << min_solution() << '\n';
  std::cout << max_solution() << '\n';
}