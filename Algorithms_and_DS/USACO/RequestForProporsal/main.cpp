#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n,k;
  std::string x;
  int count = 0;

  while (scanf("%d %d", &n, &k) != EOF)
  {
    count++;
    double price = 2000000000, p;
    int reqMet = -1, rm;
    std::string name, nam;

    for (int i = 0; i < n; i++)
    {
      std::cin.ignore();
      getline(std::cin, x);
    }

    while (k--) {
      getline(std::cin,nam);
      scanf("%lf %d\n", &p, &rm);
      if (rm > reqMet)
      {
        reqMet = rm;
        name = nam;
        price = p;
      }
      else if (rm == reqMet && p < price)
      {
        reqMet = rm;
        name = nam;
        price = p;
      }

      for (int i = 0; i < rm; i++)
      {
        getline(std::cin, x);
      }
    }
    if (count > 1) std::cout << '\n';
    std::cout << "RFP #" << count << '\n';
    std::cout << name << '\n';
  }
  return 0;
}
