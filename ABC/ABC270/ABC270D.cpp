#include <iostream>
using namespace std;

int main() {
  int N, K, A[100], dp[10001];
  cin >> N >> K;
  for (int i = 0; i < K; i++) cin >> A[i];
  dp[0] = 0;
  for (int l = 1; l <= N; l++) {
    int m = -1;
    for (int i = 0; i < K && A[i] <= l; i++) m = max(m, A[i] + l - A[i] - dp[l - A[i]]);
    dp[l] = m;
  }
  cout << dp[N] << endl;
  return 0;
}
