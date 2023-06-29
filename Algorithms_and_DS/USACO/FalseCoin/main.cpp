#include <bits/stdc++.h>

int main()
{
  int tests;
  std::cin >> tests;
  while(tests--)
  {
    int n,k,h; char c;
    std::cin >> n >> k;
    bool arr[n];
    for(int i = 0; i < n; i++) arr[i] = false;

    for(int i = 0; i < k; i++)
    {
      std::cin >> h;
      int bool_arr[2*h];
      for(int j = 0; j < 2*h; j++)
      {
        std::cin >> bool_arr[j];
      }
      std::cin >> c;
      if(c=='=')
      {
        for(int m = 0; m < 2*h; m++)
        {
          arr[bool_arr[m]-1] = true;
        }
      }

    }

    int count = 0, answer = 0;
    for(int i = 0; i < n; i++)
    {
      if(arr[i]== false)
      {
        ++count;
        answer = i+1;
      }
    }

    if(count==1)
    {
      std::cout << '\n' << answer;
    }
    else std::cout << '\n' << 0;
  }

}
