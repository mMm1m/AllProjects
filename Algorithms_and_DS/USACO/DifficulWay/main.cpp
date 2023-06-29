#include <bits/stdc++.h>

int main() {
  int t; std::cin >> t;
  while (t--) {
    int a, b, c, d, e, f, ans = 0;
    std::cin >> b >> a >> d >> c >> f >> e;
    if (a == c && e < a) ans = abs(b - d);
    else if (c == e && a < c) ans = abs(d - f);
    else if (a == e && c < a) ans = abs(b - f);
    std::cout << ans << "\n";
  }
}
