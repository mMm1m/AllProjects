#include <bits/stdc++.h>

int main()
{
  int t;
  std::cin >> t;
  std::vector<std::pair<int,int>> odd_, even_;
  while(t--)
  {
    int n;
    std::cin >> n;
    odd_.clear(); even_.clear();
    for(int i = 0; i < n; i++)
    {
      int a; std::cin >> a;
      if(a%2==0)
        even_.push_back(std::make_pair(a,i+1));
      else
        odd_.push_back(std::make_pair(a,i+1));
    }
    if(odd_.size()>=3)
      std::cout << "YES\n" << odd_[0].second << " " << odd_[1].second << " " << odd_[2].second << '\n';
    else if(odd_.size()>=1 && even_.size()>=2)
      std::cout << "YES\n" << even_[0].second << " " << even_[1].second << " " << odd_[0].second << '\n';
    else std::cout << "NO\n";
  }
}
