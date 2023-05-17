#include <iostream>
using namespace std;

long long dp[2001][2001];

int main() {
  int N, M, A[2000];
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> A[i];
  dp[0][0] = 0;
  dp[0][1] = -1e18;
  for (int i = 1; i <= N; i++) {
    dp[i][0] = 0;
    for (int j = 1; j <= M; j++) {
      if (j > i) dp[i][j] = -1e18;
      else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + j * A[i-1]);
    }
  }
  long long ans = -1e18;
  for (int i = 1; i <= N; i++) ans = max(ans, dp[i][M]);
  cout << ans << endl;
  return 0;
}
