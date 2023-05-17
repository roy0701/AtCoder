#include <iostream>
using namespace std;

int dp[51][51][10001];

int main() {
  int W, N, K, A[51], B[51];
  cin >> W;
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
  for (int k = 0; k <= K; k++) {
    for (int w = 0; w <= W; w++) dp[0][k][w] = 0;
  }
  for (int i = 1; i <= N; i++) {
    for (int w = 0; w <= W; w++) dp[i][0][w] = 0;
    for (int k = 1; k <= K; k++) {
      dp[i][k][0] = 0;
      for (int w = 1; w <= W; w++) {
        if (A[i] > w) dp[i][k][w] = dp[i-1][k][w];
        else dp[i][k][w] = max(dp[i-1][k][w], dp[i-1][k-1][w-A[i]] + B[i]);
      }
    }
  }
  cout << dp[N][K][W] << endl;
  return 0;
}
