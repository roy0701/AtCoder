#include <iostream>
using namespace std;

const int mod = 1000000007;
long long fact[1001000];

void calcFact() {
  fact[0] = 1;
  for (int i = 1; i <= 1001000; i++) fact[i] = fact[i-1] * i % mod;
}

long long power(long long x, int n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    long long y = power(x, n / 2);
    return y * y % mod;
  } else {
    return x * power(x, n - 1) % mod;
  }
}

long long divide(long long n, long long m) {
  return n * power(m, mod - 2) % mod;
}

int main() {
  int N, A, B, C, D;
  long long dp[1001][1001];
  cin >> N >> A >> B >> C >> D;
  calcFact();
  dp[A-1][0] = 1;
  for (int j = 1; j <= B; j++) dp[A-1][j] = 0;
  for (int i = A; i <= B; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= N; j++) {
      long long x = dp[i-1][j];
      for (int k = C; k <= D; k++) {
        if (i * k > j) break;
        long long n = dp[i-1][j-i*k] * fact[N-j+i*k] % mod;
        long long d = (fact[N-j] * power(fact[i], k) % mod) * fact[k] % mod;
        x = (x + divide(n, d)) % mod;
      }
      dp[i][j] = x;
    }
  }
  cout << dp[B][N] << endl;
  return 0;
}
