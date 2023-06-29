#include <bits/stdc++.h>
std::vector<int> hay;
int n;

int explosion(int index, int diff)
{
  int radius=1,end=index;
  while(true)
  {
    int temp = end;
    while(temp+radius>=0 && temp+radius<n && std::abs(hay[temp+diff]-hay[end])<=radius)
      temp+=diff;
    if(temp==end) break;
    end = temp;
    ++radius;
  }
  return std::abs(end-index);
}

int main()
{
  freopen("angry.in","r",stdin);

  freopen("angry.out","w",stdout);
  std::cin >> n;
  for(int i = 0; i < n; ++i) {int val; std::cin >> val; hay.push_back(val);}
  std::sort(hay.begin(), hay.end());
  int ans = 0;
  for(int i = 0; i < n; ++i)
    ans = std::max(ans, explosion(i,-1)+ explosion(i,1));
  std::cout << ans;
}
