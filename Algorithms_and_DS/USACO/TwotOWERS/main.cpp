#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    reverse(t.begin(), t.end());
    s += t;
    int cnt = 0;
    for (int i = 1; i < n + m; ++i) cnt += s[i - 1] == s[i];
    cout << (cnt <= 1 ? "YES\n" : "NO\n");
  }
}
