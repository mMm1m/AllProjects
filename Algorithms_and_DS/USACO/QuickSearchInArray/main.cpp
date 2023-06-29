#include <bits/stdc++.h>

std::vector<int> countingSort(const std::vector<int>& arr)
{
  std::vector< int > a(20, 0);
  for (long i = 0; i < arr.size(); i++) a[arr[i]]++;
  return a;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for(auto& a : v)
    std::cin >> a;
  std::vector<int> vector = countingSort(v);
  std::vector<int> prefix(vector.size()+1);
  for(int i = 0; i < vector.size()+1; i++)
  {
    prefix[i+1] += prefix[i] + vector[i];
  }
  /*for(auto& a : vector)
    std::cout << a << " ";
  std::cout << '\n';
  for(auto& a : prefix)
    std::cout << a << " ";
  std::cout << '\n';*/
  int k;
  std::cin >> k;
  for(int i = 0; i < k; i++)
  {
    int l,r;
    std::cin >> l >> r;
    std::cout << prefix[r+1] - prefix[l] << " ";
  }
  /**/

}
