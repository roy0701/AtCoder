#include <iostream>
using namespace std;

int dp[1001][10001];

int main() {
  int H, N, A[1001], B[1001];
  cin >> H >> N;
  for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
  dp[0][0] = 0;
  for (int j = 1; j <= H; j++) dp[0][j] = 2147483647;
  for (int i = 1; i <= N; i++) {
    dp[i][0] = 0;
    for (int j = 1; j <= H; j++) {
      if (j > A[i]) dp[i][j] = min(dp[i-1][j], dp[i][j-A[i]] + B[i]);
      else dp[i][j] = min(dp[i-1][j], B[i]);
    }
  }
  cout << dp[N][H] << endl;
  return 0;
}
