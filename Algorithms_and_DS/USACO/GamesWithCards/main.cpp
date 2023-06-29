#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int n,m, max_alice = 0, max_bob = 0; std::cin >> n;
    for(int i = 0;  i< n; ++i)
    {
      int val; std::cin >> val;
      max_alice = std::max(max_alice, val);
    }
    std::cin >> m;
    for(int i = 0;  i< m; ++i)
    {
      int val; std::cin >> val;
      max_bob = std::max(max_bob, val);
    }
    if(max_alice==max_bob) std::cout << "Alice\n" << "Bob\n";
    else if(max_alice > max_bob) std::cout << "Alice\n" << "Alice\n";
    else
      std::cout << "Bob"
                   "\n" << "Bob\n";
  }
}
