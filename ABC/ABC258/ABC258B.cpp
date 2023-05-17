#include <iostream>
using namespace std;

int main() {
  int N, A[10][10];
  long long k;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> k;
    for (int j = N-1; j >= 0; j--) {
      A[i][j] = k % 10;
      k /= 10;
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int p = -1; p <= 1; p++) {
        for (int q = -1; q <= 1; q++) {
          if (p == 0 && q == 0) continue;
          long long x = A[i][j];
          for (k = 1; k < N; k++) {
            x *= 10;
            int r = i + k * p;
            int c = j + k * q;
            if (r >= N) r -= N;
            if (r < 0) r += N;
            if (c >= N) c -= N;
            if (c < 0) c += N;
            x += A[r][c];
          }
          ans = max(ans, x);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
