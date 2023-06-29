#include <bits/stdc++.h>
using vp =  std::vector <std::pair<int,int>>;

int smol(std::vector<int>& a) {
  return std::min_element(a.begin(), a.end()) - a.begin()+1;
}

int big(std::vector<int>& a) {
  return std::max_element(a.begin(), a.end()) - a.begin()+1;
}

void solve() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  for(auto& x : a) std::cin >> x;

  if(a[smol(a)-1] == a[big(a)-1]) {
    std::cout << 0 << '\n';
    return;
  }

  if(a[smol(a)-1] == 1) {
    std::cout << -1 << '\n';
    return;
  }

  vp ans;
  while(1) {
    int i = big(a), j = smol(a);
    if(a[i-1] == a[j-1]) break;
    ans.emplace_back(i, j);
    a[i-1] = (a[i-1] + a[j-1] - 1) / a[j-1];
  }

  std::cout << ans.size() << '\n';
  for(auto& x : ans)
    std::cout << x.first << " " << x.second << '\n';
}

int main() {
  int t;
  std::cin >> t;
  while(t--) solve();
}
