#include <bits/stdc++.h>

const int MAX = 1e5;

int main()
{
  int T, current_bit, count = 0;
  std::cin >> T;
  char arr[MAX+5];
  std::vector<int> memory(100, 0);
  for(int i = 0; i < T; i++)
  {
    current_bit = 0;
    scanf("%s", &arr);
    for(int j = 0; j < strlen(arr); j++)
    {
      if(arr[j] == '+')
      {
        ++memory[current_bit];
        if(memory[current_bit]==256)
          memory[current_bit] = 0;
      }
      else if(arr[j] == '-')
      {
        --memory[current_bit];
        if(memory[current_bit]==-1)
          memory[current_bit] = 255;
      }
      else if(arr[j] == '<')
      {
        --current_bit;
        if(current_bit==-1)
          current_bit = 99;
      }
      else
      {
        ++current_bit;
        if(current_bit==256)
          current_bit = 0;
      }
    }
    printf("Case %d:", ++count);
    for (int k = 0; k < 100; ++k)
      printf(" %02X", memory[k]);
    printf("\n");
  }
}
