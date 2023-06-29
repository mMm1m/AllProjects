#include <bits/stdc++.h>

int main()
{
  int t; std::cin >> t;
  while(t--)
  {
    int x,y,z, note_x, note_y, lamp_x, lamp_y;
    std::cin >> x >> y >> z >> note_x >> note_y >> lamp_x >> lamp_y;
    int front = std::abs(note_x-lamp_x)+note_y+lamp_y+z,
    back = std::abs(note_x-lamp_x)+(y-note_y)+(y-lamp_y)+z,
    left = note_x+std::abs(note_y-lamp_y)+z+lamp_x,
    right = x-note_x+std::abs(note_y-lamp_y)+z+x-lamp_x;
    int min = std::min({front, back, left, right});
    std::cout <<  min << '\n';
  }
}
