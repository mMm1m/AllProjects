#include <bits/stdc++.h>

int main()
{
  std::string str;
  while(getline(std::cin, str), str != "DONE")
  {
    std::string new_str = "";
    for(int i = 0; i < str.size(); i++)
    {
      if(std::isalpha(str[i]))
        new_str += tolower(str[i]);
    }
    std::string reverse_order = "";
    for(int i = new_str.size()-1; i >= 0; i--)
      reverse_order += new_str[i];
    if(new_str==reverse_order) std::cout << "You won’t be eaten!" << '\n';
    else std::cout << "Uh oh.." << '\n';
  }
}
