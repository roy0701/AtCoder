#include <iostream>
using namespace std;

int main() {
  int N, M, count[100];
  string s[100], t[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> s[i];
  cin >> M;
  for (int j = 0; j < M; j++) cin >> t[j];
  for (int i = 0; i < N; i++) {
    count[i] = 0;
    for (int k = 0; k <= i; k++) {
      if (s[i] == s[k]) {
        count[k]++;
        break;
      }
    }
  }
  for (int j = 0; j < M; j++) {
    for (int k = 0; k < N; k++) {
      if (t[j] == s[k]) {
        count[k]--;
        break;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) ans = max(ans, count[i]);
  cout << ans << endl;
  return 0;
}
