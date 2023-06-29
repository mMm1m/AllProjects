#include <bits/stdc++.h>

int main()
{
  int n,k;
  std::cin >> n >> k;
  std::vector<int> diamonds(n);
  for(auto& a : diamonds)
    std::cin >> a;
  std::sort(diamonds.begin(), diamonds.end());

   std::vector<int> first_step(n), second_step(n+1);
   // find the most useful leftside diamond
   int right = 0;
   for(int left = 0; left < n; left++)
   {
     while(right < n && diamonds[right]-diamonds[left] <= k) right++;
     first_step[left] = right - left;
   }

   second_step[n] = 0;
   for(int i = n-1; i >= 0; i--)
     second_step[i] = std::max(second_step[i+1],first_step[i]);

   int answer = 0;
   // calculate answer
   for(int i = 0; i < n; i++)
     answer = std::max(answer, first_step[i]+second_step[i+first_step[i]]);
   std::cout << answer;

   for(auto& a : diamonds)
     std::cout << a << " ";
   std::cout << '\n';
  for(auto& a : first_step)
    std::cout << a << " ";
  std::cout << '\n';

   /*second_step[n] = 0;
   for(int idx = n-1; idx >= 0; idx--)
   {}*/

}
