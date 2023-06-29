#include <bits/stdc++.h>

int main()
{
  freopen("breedflip.in", "r", stdin);
  freopen("breedflip.out", "w", stdout);
  int N;
  std::cin >> N;
  std::string string1, string2;
  std::cin >> string1 >> string2;
  int count = 0;
  bool flag = false;
  for(int i = 0; i < N; i++)
  {
    if(string1[i] != string2[i])
    {
      if(!flag)
      {
        flag = true;
        count++;
      }
    }
    else
      flag = false;
  }
  std::cout << count;
}
