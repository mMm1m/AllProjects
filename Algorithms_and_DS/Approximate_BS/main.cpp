#include <bits/stdc++.h>


int main()
{
  int n,k, t; std::cin >> n >> k;
  std::vector<int> v(n);
  for(int i = 0; i < n; ++i ) {std::cin >> t; v[i] = t;}
  for(int i= 0; i < k; ++i)
  {
    std::cin >> t;
    if(t > v[n-1]) {std::cout << v[n-1] << '\n';}
    else if(t < v[0]) {std::cout << v[0] << '\n';}
    else
    {
      auto lb = std::lower_bound(v.begin(),v.end(),t);
      int ans;
      if( *lb == t) {ans = t;}
      else
      {
        if(t-v[lb-v.begin()-1] <= v[lb-v.begin()]-t)
        {
          ans = v[lb-v.begin()-1];
        }
        else ans = v[lb-v.begin()];
      }
      std::cout << ans << '\n';
    }
  }
}
