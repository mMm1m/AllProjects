#include <bits/stdc++.h>

const int constanta = 1e5;

int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a%b);
}

int main()
{
  int arr[constanta], prefix[constanta], suffix[constanta];
  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++)
    std::cin >> arr[i];

  prefix[0] = 0;
  suffix[n+1] = 0;

  for(int i = 1; i <= n; i++)
    prefix[i] = gcd(prefix[i-1],arr[i]);

  for(int j = n; j >= 1; j--)
    suffix[j] = gcd(suffix[j-1],arr[j]);

  int answer = 0;
  for(int i = 1; i <= n; i++)
    answer = std::max(answer, gcd(prefix[i-1], suffix[i+1]));
}
