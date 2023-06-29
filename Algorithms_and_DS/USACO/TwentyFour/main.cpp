#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;

// Function that takes in two numbers and an operation and returns the result.
int operation(int op, int num1, int num2) {
  switch (op) {
    case 0:
      return num1 + num2;
    case 1:
      return num1 - num2;
    case 2:
      return num1 * num2;
    case 3: {
      // The divisor cannot be 0 and the quotient must be a whole number.
      if (num2 == 0 || num1 % num2) { return -INF; }
      return num1 / num2;
    }
  }
  return -INF;
}

int main() {
  int num_hands;
  cin >> num_hands;

  for (int h = 0; h < num_hands; h++) {
    vector<int> hand(4);
    for (int i = 0; i < 4; i++) { cin >> hand[i]; }
    sort(hand.begin(), hand.end());

    int ans = -INF;
    // Start complete search.
    do {
      // Case 1: ((( ) ) )
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          for (int k = 0; k < 4; k++) {
            int first = operation(i, hand[0], hand[1]);
            // If the operation is invalid, continue;
            if (first == -INF) { continue; }

            int second = operation(j, first, hand[2]);
            if (second == -INF) { continue; }

            int third = operation(k, second, hand[3]);
            if (third == -INF) { continue; }

            if (third <= 24) { ans = max(ans, third); }
          }
        }
      }

      // Case 2: (( ) ( ))
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          for (int k = 0; k < 4; k++) {
            int first = operation(i, hand[0], hand[1]);
            if (first == -INF) { continue; }

            int second = operation(j, hand[2], hand[3]);
            if (second == -INF) { continue; }

            int third = operation(k, first, second);
            if (third == -INF) { continue; }

            if (third <= 24) { ans = max(ans, third); }
          }
        }
      }
    } while (next_permutation(hand.begin(), hand.end()));
    cout << ans << "\n";
  }
}