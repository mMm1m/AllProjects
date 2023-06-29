#include <iostream>

int main()
{
  int odd=0, even=0, N, x;
  std::cin >> N;
  for (int i=0; i<N; i++) {
    std::cin >> x;
    if (x % 2 == 0) even++; else odd++;
  }
  while (odd > even) { odd-=2; even++; }
  if (even > odd+1) even = odd+1;
  std::cout << even + odd << "\n";
}
