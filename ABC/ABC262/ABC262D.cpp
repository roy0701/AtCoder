#include <iostream>
using namespace std;

int main() {
  int N, a[100], dp[101][102][100];
  int mod = 998244353;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = 0; k <= i; k++) {
        for (int l = 0; l < i; l++) dp[j][k][l] = 0;
      }
    }
    dp[0][0][0] = 1;
    for (int j = 0; j < N; j++) {
      for (int k = 0; k <= i; k++) {
        for (int l = 0; l < i; l++) {
          dp[j+1][k][l] = (dp[j+1][k][l] + dp[j][k][l]) % mod;
          dp[j+1][k+1][(l+a[j])%i] = (dp[j+1][k+1][(l+a[j])%i] + dp[j][k][l]) % mod;
        }
      }
    }
    ans = (ans + dp[N][i][0]) % mod;
  }
  cout << ans << endl;
  return 0;
}
