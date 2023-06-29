#include <bits/stdc++.h>

int main() {
  int N, M; std::cin >> N >> M;
  int A[M], B[M], G[N];
  freopen("revegetate.in","r",stdin);
  freopen("revegetate.out", "w", stdout);
  for (int i = 0; i < M; i++)
  {
    std::cin >> A[i] >> B[i];
    if (A[i] > B[i]) std::swap(A[i], B[i]);
  }
  for (int i = 1; i <= N; i++) {
    int g;
    for (g = 1; g <= 4; g++) {
      bool ok = true;
      for (int j = 0; j < M; j++)
        if (B[j] == i && G[A[j]] == g) ok = false;
      if (ok) break;
    }
    G[i] = g;
    std::cout << g;
  }
}
