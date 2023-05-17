#include <algorithm>
#include <iostream>
using namespace std;

int P, g[18];

bool setGirls(int k) {
  int n = 0;
  int x = 0;
  while (k > 0) {
    if (x == P) return false;
    if (k % 2 == 1) {
      g[x] = n;
      x++;
    }
    k /= 2;
    n++;
  }
  return x == P;
}

int main() {
  int N, M, Q, R, x, y, z, a[18][18], score[18];
  cin >> N >> M >> P >> Q >> R;
  for (x = 0; x < N; x++) {
    for (y = 0; y < M; y++) a[x][y] = 0;
  }
  for (int i = 0; i < R; i++) {
    cin >> x >> y >> z;
    a[x - 1][y - 1] = z;
  }
  int ans = 0;
  for (int k = 0; k < 1 << N; k++) {
    if (setGirls(k)) {
      for (y = 0; y < M; y++) {
        score[y] = 0;
        for (x = 0; x < P; x++) score[y] += a[g[x]][y];
      }
      sort(score, score + M);
      int sum = 0;
      for (int y = 0; y < Q; y++) sum += score[M - y - 1];
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
