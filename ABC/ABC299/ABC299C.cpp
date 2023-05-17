#include <iostream>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  int ans = -1;
  int pos, i;
  if (S[0] == 'o') {
    for (i = 1; i < N; i++) {
      if (S[i] == '-') {
        pos = i;
        ans = i;
        break;
      }
    }
  } else {
    for (i = 1; i < N; i++) {
      if (S[i] == 'o') {
        pos = i - 1;
        ans = 1;
        break;
      }
    }
  }
  if (ans == -1) {
    cout << -1 << endl;
    return 0;
  }
  for (i = pos; i < N; i++) {
    if (S[i] == '-') {
      ans = max(ans, i - pos - 1);
      pos = i;
    }
  }
  ans = max(ans, N - pos - 1);
  cout << ans << endl;
  return 0;
}
