#include <bits/stdc++.h>

int main()
{
  int tests, count = 0;
  std::cin >> tests;
  while (tests--) {
    int n;
    std::cin >> n;
    int available_petrol[n], need_petrol[n];
    for (int i = 0; i < n; i++) std::cin >> available_petrol[i];
    for (int i = 0; i < n; i++) std::cin >> need_petrol[i];

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += (available_petrol[i]-need_petrol[i]);
      if(sum < 0)
      {
        std::cout << "Case " << ++count << ":" << " Not possible" << '\n';
        continue;
      }
    }

    int i = 0, j = 0; sum = 0;
    bool flag = false;
    while (true) {
      if (i == j && flag) {
        break;
      }
      flag = true;
      sum += available_petrol[j] - need_petrol[j];
      j = (j + 1) % n;
      while (sum < 0) {
        flag = false;
        sum -= available_petrol[i] - need_petrol[i];
        i++;
      }
    }

    std::cout << "Case " << ++count << " Possible from station " << i+1 << '\n';
  }
}
