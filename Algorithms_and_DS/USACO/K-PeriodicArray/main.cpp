#include <bits/stdc++.h>

int main(){

  int n, k;
  std::cin >> n >> k;

  std::vector<bool> array;
  for(int p = 0; p < n; p++)
  {
    int temp;
    std::cin >> temp;
    array.push_back(temp - 1);
  }

  int total(0);
  for(int p = 0; p < k; p++){
    int partial(0);
    for(int q = p; q < n; q += k)
    {partial += array[q];}
    total += (partial < n/k - partial) ? partial : (n/k - partial);
  }

  printf("%d\n", total);
  return 0;
}