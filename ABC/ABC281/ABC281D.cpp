#include <iostream>
using namespace std;

int main() {
  int N, K, D;
  long long a[101], dp[101][101][100];
  cin >> N >> K >> D;
  for (int i = 1; i <= N; i++) cin >> a[i];
  dp[0][0][0] = 0;
  for (int l = 1; l < D; l++) dp[0][0][l] = -1;
  for (int i = 1; i <= N; i++) {
    dp[i][0][0] = 0;
    for (int l = 1; l < D; l++) dp[i][0][l] = -1;
    for (int k = 1; k <= i && k <= K; k++) {
      for (int l = 0; l < D; l++) {
        int m = l - a[i] % D;
        if (m < 0) m += D;
        dp[i][k][l] = i-1 >= k ? dp[i-1][k][l] : -1;
        if (dp[i-1][k-1][m] >= 0) dp[i][k][l] = max(dp[i][k][l], dp[i-1][k-1][m] + a[i]);
      }
    }
  }
  cout << dp[N][K][0] << endl;
  return 0;
}
