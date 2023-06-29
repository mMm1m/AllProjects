#include <bits/stdc++.h>

int alphabet[26];
std::vector<std::string> vector;
std::string string;

int main()
{
  std::cin >> string;
  std::sort(string.begin(), string.end());
  do
  {
    vector.push_back(string);
  } while (std::next_permutation(string.begin(), string.end()));
  std::cout << vector.size() << "\n";
  for(auto& s : vector)
    std::cout << s << "\n";
}
