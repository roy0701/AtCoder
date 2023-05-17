#include <iostream>
using namespace std;

int main() {
  int N, M, distA[100000], distB[100000];
  string S[100000];
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < N; i++) {
    distA[i] = 1000000;
    distB[i] = 1000000;
  }
  distA[0] = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < M; j++) {
      if (S[i][j] == '1') {
        distA[i + j + 1] = min(distA[i + j + 1], distA[i] + 1);
      }
    }
  }
  distB[N - 1] = 0;
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j < M; j++) {
      if (S[i][j] == '1') {
        distB[i] = min(distB[i], distB[i + j + 1] + 1);
      }
    }
  }
  for (int k = 1; k < N - 1; k++) {
    int ans = 1000000;
    for (int i = max(0, k - M); i < k; i++) {
      for (int j = k + 1; j < N && j - i <= M; j++) {
        if (S[i][j - i - 1] == '1') {
          ans = min(ans, distA[i] + 1 + distB[j]);
        }
      }
    }
    cout << (ans == 1000000 ? -1 : ans) << endl;
  }
  return 0;
}
