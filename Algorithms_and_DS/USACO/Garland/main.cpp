#include <bits/stdc++.h>

const int constanta = 1500;
std::string str;
int n;

int solution()
{
  int val;
  char c;
  for(int i = 0; i < n; i++) {
    std::cin >> val >> c;

    int left = 0, right = 0, answer = 0;
    while (left < n && right < n) {
      while (right < n) {
        if (str[right] != c) {
          if (val == 0) break;
          val--;
        }
        right++;
      }
      answer = std::max(answer, right - left + 1);
      val += (str[left] != c);
      left++;
    }
  }
  return answer;
}

int main()
{
  int q;
  std::cin >> q;
  std::cin >> str;
  std::cin >> n;
  for(int i = 0; i < q; i++)
    std::cout << solution() << '\n';
}
