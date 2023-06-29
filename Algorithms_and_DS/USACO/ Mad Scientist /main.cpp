#include <bits/stdc++.h>

int main()
{
  freopen("breedflip.in","r",stdin);
  freopen("breedflip.out","w",stdout);
  int n; std::cin >> n;
  std::string a,b; std::cin >> a >> b;
  bool flag = true; int cnt = 0;
  for(int i = 0; i < n; ++i)
  {
    if((a[i]!=b[i]) && flag) {++cnt; flag=false;}
    else if((a[i]==b[i]) && !flag) flag = true;
  }
  std::cout << cnt;
}
