#include <bits/stdc++.h>

int main()
{
  int n,k;
  std::cin >> n >> k;
  std::vector<int> difference(n,0), prefix_sums(n,0);
  for(int i = 0; i < k; i++)
  {
    int left, right;
    std::cin >> left >> right;
    --left; --right;
    difference[left]++;
    difference[++right]--;
  }

  for(auto& a : difference)
    std::cout << a << " ";
  std::cout << "\n";

  for(int i = 1; i < n; i++)
    prefix_sums[i] = prefix_sums[i-1]+ difference[i];

  std::sort(prefix_sums.begin(), prefix_sums.end());

  for(auto& a : prefix_sums)
    std::cout << a << " ";
  std::cout << "\n";

  std::cout << prefix_sums[n/2];
}

