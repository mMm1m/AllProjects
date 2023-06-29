#include <bits/stdc++.h>

int main(){
  freopen("diamond.in","r",stdin);
  freopen("diamond.out","w",stdout);
  int n,k; std::cin >> n >> k;
  std::vector<int> diamond(n); for(auto& a : diamond) std::cin >> a;
  std::sort(diamond.begin(), diamond.end());
  int count = 0;
  for(int i = 0; i < n; ++i)
  {
    int curr = 0;
    for(int j = i; j < n; ++j)
    {
      if(diamond[j]-diamond[i]<=k) ++curr;
      else break;
    }
    count = std::max(count, curr);
  }
  std::cout << count << '\n';
}