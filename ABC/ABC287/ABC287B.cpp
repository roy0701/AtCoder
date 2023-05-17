#include <iostream>
using namespace std;

int main() {
  int N, M, S[1000], T[1000];
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    S[i] %= 1000;
  }
  for (int j = 0; j < M; j++) cin >> T[j];
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (S[i] == T[j]) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
