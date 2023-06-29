#include <bits/stdc++.h>

bool sorted(std::vector<int>& v)
{
  auto a = v;
  bool flag= true;
  std::sort(a.begin(), a.end());
  for(int i = 0; i < v.size(); i++)
  {
    if(a[i]-v[i]!=0) {flag = false; break;}
  }
  return flag;
}

int main()
{
  int t;
  std::cin >> t;
  while(t--)
  {
    int n;
    std::cin >> n;
    std::vector<int> arr(n); for(auto& a : arr) {
      std::cin >> a;
    }

    int i = 0, j = 0;
    while (i < n) {
      if (arr[i] < 0) {
        arr[j++] *= -1;
        arr[i] *= -1;
      }
      i++;
    }
    if (sorted(arr)) {
      std::cout << "YES\n";
    } else
      std::cout << "NO\n";
  }
  }
