#include <iostream>
using namespace std;

int main() {
  int N, A[10], M, B, X;
  bool mochi[100001], dp[100001];
  for (int s = 0; s <= 100000; s++) {
    mochi[s] = false;
    dp[s] = false;
  }
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cin >> M;
  for (int j = 0; j < M; j++) {
    cin >> B;
    mochi[B] = true;
  }
  cin >> X;
  dp[0] = 1;
  for (int s = 1; s <= X; s++) {
    if (mochi[s]) {
      continue;
    }
    for (int i = 0; i < N; i++) {
      if (s - A[i] >= 0) {
        if (dp[s - A[i]]) {
          dp[s] = true;
          break;
        }
      }
    }
  }
  cout << (dp[X] ? "Yes" : "No") << endl;
  return 0;
}
