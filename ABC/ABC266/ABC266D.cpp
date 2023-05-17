#include <iostream>
using namespace std;

int main() {
  int N, T[100000], X[100000], A[100000], i;
  long long dp[100001][5];
  cin >> N;
  for (i = 0; i < N; i++) cin >> T[i] >> X[i] >> A[i];
  dp[0][0] = 0;
  for (int x = 1; x < 5; x++) dp[0][x] = -1e18;
  i = 0;
  for (int t = 1; t <= 100000; t++) {
    for (int x = 0; x < 5; x++) {
      dp[t][x] = dp[t-1][x];
      if (x > 0) dp[t][x] = max(dp[t][x], dp[t-1][x-1]);
      if (x < 4) dp[t][x] = max(dp[t][x], dp[t-1][x+1]);
      if (t == T[i] && x == X[i]) {
        dp[t][x] += A[i];
        i++;
      }
    }
  }
  long long ans = dp[100000][0];
  for (int x = 1; x < 5; x++) ans = max(ans, dp[100000][x]);
  cout << ans << endl;
  return 0;
}
