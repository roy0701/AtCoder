#include <iostream>
using namespace std;

int main() {
  int N, M, k[100], x[100][100];
  bool join[100][100];
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++) {
      cin >> x[i][j];
      x[i][j]--;
    }
  }
  for (int j = 0; j < N; j++) {
    for (int l = 0; l < N; l++) join[j][l] = false;
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < k[i] - 1; j++) {
      for (int l = j + 1; l < k[i]; l++) join[x[i][j]][x[i][l]] = true;
    }
  }
  bool ans = true;
  for (int j = 0; j < N - 1; j++) {
    for (int l = j + 1; l < N; l++) {
      if (!join[j][l]) {
        ans = false;
        break;
      }
    }
    if (!ans) break;
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
