#include <bits/stdc++.h>

int main()
{
  std::ifstream file("/home/max/file.txt");
  std::string s, pattern = ".......", ans = "";
  if(file.is_open())
  {
    std::cout << "OK" << '\n';
    while(getline(file,s))
    {
      if(s.size()>=7)
      {
        std::string tmp;
        for(int i = 0; i < s.size(); i++)
        {
          tmp.push_back(s[i]);
          if(tmp==pattern)
          {
            ans += tmp;
            ans += " ";
            std::cout << ans;
            return 0;
          }
        }
        ans += tmp;
        ans += " ";
      }
      else
      {
        ans += s;
        ans += " ";
      }
    }
  }
  std::cout << ans;
  file.close();
}
