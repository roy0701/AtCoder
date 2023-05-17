#include <iostream>
using namespace std;

int main() {
  int N, M;
  string S[30];
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> S[i];
  int ans = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      bool possible = true;
      for (int k = 0; k < M; k++) {
        if (S[i][k] == 'x' && S[j][k] == 'x') {
          possible = false;
          break;
        }
      }
      if (possible) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
