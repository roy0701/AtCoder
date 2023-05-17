#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, S, a[100], b[100], dp[100][10001];
  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
  for (int j = 0; j <= S; j++) dp[0][j] = 0;
  dp[0][a[0]] = 1;
  dp[0][b[0]] = 2;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= S; j++) {
      dp[i][j] = 0;
      if (j-a[i] >= 0 && dp[i-1][j-a[i]]) dp[i][j] = 1;
      if (j-b[i] >= 0 && dp[i-1][j-b[i]]) dp[i][j] = 2;
    }
  }
  if (dp[N-1][S]) {
    cout << "Yes" << endl;
    string ans = "";
    int j = S;
    for (int i = N-1; i >= 0; i--) {
      if (dp[i][j] == 1) {
        ans = "H" + ans;
        j -= a[i];
      } else {
        ans = "T" + ans;
        j -= b[i];
      }
    }
    cout << ans << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
