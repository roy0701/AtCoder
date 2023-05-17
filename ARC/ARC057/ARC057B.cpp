#include <iostream>
using namespace std;

long dp[2001][2001];

int main() {
  long N, K, a[2001];
  cin >> N >> K;
  long sum = 0;
  for (long i = 1; i <= N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum == K) {
    cout << 1 << endl;
    return 0;
  }
  dp[1][0] = 0;
  dp[1][1] = 1;
  long games = a[1];
  for (long i = 2; i <= N; i++) {
    dp[i][0] = 0;
    dp[i][1] = 1;
    for (long j = 2; j < i; j++) {
      long win = dp[i-1][j-1] * a[i] / games + 1;
      dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + win);
    }
    if (a[1] == 1) {
      dp[i][i] = 2e9;
    } else {
      long win = dp[i-1][i-1] * a[i] / games + 1;
      dp[i][i] = dp[i-1][i-1] + win;
    }
    games += a[i];
  }
  long ans = 0;
  for (long j = 1; j <= N; j++) {
    if (dp[N][j] <= K) ans = j;
    else break;
  }
  cout << ans << endl;
  return 0;
}
