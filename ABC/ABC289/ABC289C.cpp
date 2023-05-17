#include <iostream>
using namespace std;

int main() {
  int N, M, C[10], a[10][10];
  bool exist[11];
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> C[i];
    for (int j = 0; j < C[i]; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int b = 0; b < 1 << M; b++) {
    for (int n = 1; n <= N; n++) {
      exist[n] = false;
    }
    int cnt = 0;
    int bb = b;
    for (int i = 0; i < M; i++) {
      if (bb % 2 == 0) {
        for (int j = 0; j < C[i]; j++) {
          if (!exist[a[i][j]]) {
            exist[a[i][j]] = true;
            cnt++;
          }
        }
      }
      bb /= 2;
    }
    if (cnt == N) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
