#include <bits/stdc++.h>

int operation(int n)
{
  int curr = n, ans = 0;
  do
  {
    curr /= 2;
    ++ans;
  } while((curr%2)==(n%2) && curr >= 0);
  return ans;
}

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n, sum=0;
    std::cin >> n;
    std::vector<int> v(n); for(auto& a : v) {std::cin >> a;sum+=a; }
    if(sum%2==0) std::cout << 0 << '\n';
    else
    {
      int x = 1e9;
      for(int i=0; i<n; i++)
        x = std::min(operation(v[i]),x);
      std::cout << x << '\n';
    }
  }
}
