#include <bits/stdc++.h>

const int constanta = 2019;

int main()
{
  std::string input;
  std::cin >> input;
  int count[constanta];
  count[0] = 1;
  int size_ = input.size()-1;

  int number = 0, pow = 1;
  long long answer = 0;
  for(int i = size_; i >= 0; i--)
  {
    number = (number+pow*(input[i]-'0'))%2019;
    pow = (pow*10)%2019;
    answer += count[number];
    count[number]++;
  }
  std::cout << answer;
}
