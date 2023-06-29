#include <bits/stdc++.h>

int main()
{
  freopen("sleepy.in","r",stdin);
  freopen("sleepy.out", "w", stdout);
  int n;
  std::cin >> n;
  std::vector< int > vector(n);
  for (int& a: vector)
    std::cin >> a;
  int decrease = n-1;
  for (int i = n - 2; i >= 0; i--) {
    if (vector[i] < vector[i + 1])
      decrease = i;
    else break;
  }
  std::cout << decrease;
}
