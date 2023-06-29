#include <bits/stdc++.h>

int main()
{
  int n, q;
  std::cin >> n >> q;
  std::vector<int> given_array(n);
  std::vector<int> prefix(n+1);

  for(int i = 0; i < n; i++)
    std::cin >> given_array[i];

  prefix[0]=0;
  // create prefix_sums array
  for(int i = 1; i < n+1; i++)
    prefix[i] = prefix[i-1] + given_array[i-1];

  for(int i = 0; i < q; i++)
  {
    int l,r;
    std::cin >> l >> r;
    std::cout << prefix[r] - prefix[l] << "\n";
  }
}
