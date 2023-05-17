#include <iostream>
using namespace std;

int main() {
  int N, T, C[200000], R[200000];
  cin >> N >> T;
  bool submitted = false;
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    if (C[i] == T) {
      submitted = true;
    }
  }
  for (int i = 0; i < N; i++) {
    cin >> R[i];
  }
  int winner = 0;
  if (submitted) {
    int maxR = 0;
    for (int i = 0; i < N; i++) {
      if (C[i] == T && R[i] > maxR) {
        winner = i;
        maxR = R[i];
      }
    }
  } else {
    int maxR = R[0];
    for (int i = 1; i < N; i++) {
      if (C[i] == C[0] && R[i] > maxR) {
        winner = i;
        maxR = R[i];
      }
    }
  }
  cout << winner + 1 << endl;
  return 0;
}
