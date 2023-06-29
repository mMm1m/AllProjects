#include <iostream>
#include <set>

int main()
{
  int n,a,b, case_number = 0;
  char str[1000006];
  while(scanf("%s %d", str, &n) == 2)
  {
    printf("Case %d:\n", ++case_number);
    while (n--) {
      std::set< char > elements;
      scanf("%d %d", &a, &b);
      for (int i = std::min(a, b); i <= std::max(a, b); i++) {
        elements.insert(str[i]);
      }
      if (elements.size() != 1) {
        std::cout << "No\n";
      } else {
        std::cout << "Yes\n";
      }

    }
  }
}
