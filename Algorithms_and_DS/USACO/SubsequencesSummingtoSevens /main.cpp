#include <bits/stdc++.h>

int main()
{
  freopen("div7.in","r",stdin);
  freopen("div7.out", "w", stdout);
  int n;
  std::cin >> n;

  std::array<int, 7> first;
  first.fill(INT_MAX);
  int last[7];

  long long curr = 0;
  for(int i = 1; i <= n; i++)
  {
    int value;
    std::cin >> value;
    (curr += value) %= 7;

    first[curr] = std::min(first[curr], i);
    last[curr] = i;
  }

  /*for(auto a : first)
    std::cout << a << " ";
  std::cout << "\n";
  for(auto a : last)
    std::cout << a << " ";
  std::cout << "\n";*/

  int answer = 0;
  for(int i = 0; i < 7; i++)
    if(first[i] <= n) answer = std::max(answer, last[i] - first[i]);

  std::cout << answer;
}


/*int main()
{
  int n;
  std::cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++)
    std::cin >> arr[i];

  // create prefix
  std::vector<int> prefix(n+1);
  for(int i = 0; i < n+1; i++)
    prefix[i+1] = prefix[i] + arr[i];

  int count = 0;
  for(int i = 0; i < n+1; i++)
  {
    for(int j = i+1; j < n+1; j++)
    {
      if((prefix[j]-prefix[i])%7==0)
      {
        int current = j-i;
        count = std::max(j-i, count);
      }
    }
  }

  std::cout << count;

}*/

