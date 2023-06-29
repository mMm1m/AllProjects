#include <bits/stdc++.h>

using std::cout; using std::endl; using std::vector;

int main() {
  freopen("gymnastics.in","r",stdin);
  freopen("gymnastics.out","w",stdout);
  int session_num, cow_num;
  std::cin >> session_num >> cow_num;
  vector<vector<bool>> better(cow_num, vector<bool>(cow_num));
  for (int s = 0; s < session_num; s++) {
    vector<int> session(cow_num);
    for (int &c : session) {
      std::cin >> c;
      c--;
    }
    for (int i = 0; i < session.size(); i++) {
      for (int j = i + 1; j < session.size(); j++) {
        better[session[j]][session[i]] = true;
      }
    }
  }

  int better_pairs = 0;
  for (int c1 = 0; c1 < cow_num; c1++) {
    for (int c2 = c1 + 1; c2 < cow_num; c2++) {
      better_pairs += !better[c1][c2] || !better[c2][c1];
    }
  }
  std::cout << better_pairs << endl;
}