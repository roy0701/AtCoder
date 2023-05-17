#include <iostream>
using namespace std;

int main() {
  int N, M, x, y;
  int known[12][12];
  cin >> N >> M;
  for (int k = 0; k < N; k++) {
    for (int l = 0; l < N; l++) {
      known[k][l] = false;
    }
  }
  for (int i = 0; i < M; i++) {
    cin >> x >> y;
    known[x-1][y-1] = true;
  }
  int max = 0;
  bool group[N];
  for (int s = 1; s < 1 << N; s++) {
    int s_ = s;
    int number = 0;
    for (int k = 0; k < N; k++) {
      if (s_ % 2 == 1) {
        group[k] = true;
        number++;
      } else {
        group[k] = false;
      }
      s_ /= 2;
    }
    if (number > max) {
      bool flag = true;
      for (int k = 0; k < N - 1; k++) {
        if (group[k]) {
          for (int l = k + 1; l < N; l++) {
            if (group[l] && !known[k][l]) {
              flag = false;
              break;
            }
          }
        }
        if (!flag) break;
      }
      if (flag) max = number;
    }
  }
  cout << max << endl;
  return 0;
}
