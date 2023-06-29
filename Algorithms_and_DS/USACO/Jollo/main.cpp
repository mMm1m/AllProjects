#include <bits/stdc++.h>

std::vector<int> princess(3), prince(3);

bool func(int answer)
{
  bool flag = true;
  prince[2] = answer;
  int lose_count = 0;
  std::sort(prince.begin(), prince.end());
  for(int i = 0; i < 3; i++)
  {
    if(prince[i] < princess[i])
    {
      ++lose_count;
    }
  }
  if(lose_count >= 2) flag = false;
  return flag;
}

int main()
{
  std::vector<bool> bool_vector;
  int A, B, C, X, Y;
  while(std::cin >> A >> B >> C >> X >> Y, A)
  {
    princess.clear(); prince.clear(); bool_vector.clear();
    bool_vector.resize(53, true);
    princess[0] = A; princess[1] = B; princess[2] = C;
    prince[0] = X; prince[1] = Y;
    std::sort(princess.begin(), princess.end());
    std::sort(prince.begin(), prince.end());

    for(int i = 0; i < 3; i++)
    {
      bool_vector[princess[i]] = false;
      if(i < 2)
      {
        bool_vector[prince[i]] = false;
      }
    }


    int count = 6;
    for(int i = 0; i < 2; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        count = (prince[i]<princess[j]) ? count - 1 : count + 0;
      }
    }

    int answer = 53;
    if(count >= 4)
    {
      for(int i = princess[0]; i < 53; i++)
      {
        if(bool_vector[i])
        {
          answer = i;
          if(func(answer)) break;
        }
      }
    }
    else answer = -1;
    if(answer == 53) answer = -1;
    std::cout << answer << '\n';
  }
}
