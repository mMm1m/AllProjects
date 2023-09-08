#include <bits/stdc++.h>


void print(const std::vector<int>& vector)
{
  for(auto& a : vector) {std::cout << a << " ";}
}

int main()
{
  int n, tmp; std::cin >> n;
  std::vector<int> original(n), temp(101), prefix(101), answer(n);
  for(int i = 0; i < n; ++i) {std::cin >> tmp; original[i] = tmp;}
  for(int i = 0; i < n; ++i) {++temp[original[i]];}
  for(int i = 1; i <= 100; ++i) {prefix[i] += prefix[i-1]; prefix[i] += temp[i-1];}
  for(int i = 0; i < n; ++i) answer[prefix[original[i]]++] = original[i];
  print(answer);
}
