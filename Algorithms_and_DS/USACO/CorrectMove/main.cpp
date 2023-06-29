#include <bits/stdc++.h>
int first_king_pos, first_queen_pos, second_queen_pos;
void evaluation_function(int first_king,int first_queen,int second_queen)
{
  int diff = std::max(first_king, second_queen) - std::min(first_king, second_queen);
  if(first_king == first_queen)
  {
    std::cout << "Illegal state\n";
    return;
  }
  if(std::abs(first_queen-second_queen)%8 != 0 && first_queen/8 != second_queen/8)
  {
    std::cout << "Illegal move\n";
    return;
  }
  if (((first_king - first_queen) % 8 == 0 && (first_king - second_queen) % 8 == 0) || (first_king / 8 == first_queen / 8 && first_king  / 8 == second_queen / 8))
  {
    if (first_king <= std::max(first_queen, second_queen) && first_king >= std::min(first_queen, second_queen))
    {
      std::cout << "Illegal move\n";
      return;
    }
  }
  if(diff == 8 || diff == 1 && first_king/8 == second_queen/8)
  {
    std::cout << "Move not allowed\n";
    return;
  }
  if(((first_king == 0 && second_queen == 9) || (first_king == 7 && second_queen == 14) || (first_king == 56 && second_queen == 49) || (first_king == 63 && second_queen == 54)))
  {
    std::cout << "Stop\n";
    return;
  }
  else
  {
    std::cout << "Continue\n";
    return;
  }
}

int main()
{
  while(scanf("%d%d%d", &first_king_pos, &first_queen_pos, &second_queen_pos) == 3)
  {
    evaluation_function(first_king_pos, first_queen_pos, second_queen_pos);
  }
}
