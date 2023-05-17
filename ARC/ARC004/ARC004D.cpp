#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;
int p[10000];
long long fact[32];
long long invFact[32];

int numberPF(int n) {
  int m = n;
  int k = 0;
  for (int i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      while (m % i == 0) {
        m /= i;
        p[k]++;
      }
      k++;
    }
  }
  if (m > 1) {
    p[k] = 1;
    k++;
  }
  return k;
}

long long permutation(int n, int r) {
  long long ans = 1;
  for (int i = 0; i < r; i++) ans = ans * (n - i) % mod;
  return ans;
}

long long power(long long n, int m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    long long x = power(n, m / 2);
    return x * x % mod;
  } else {
    return n * power(n, m - 1) % mod;
  }
}

long long inverse(long long n) {
  return power(n, mod - 2);
}

long long combination(int n, int r) {
  return permutation(n, r) * invFact[r] % mod;
}

void calcInvFact() {
  for (int i = 0; i < 32; i++) {
    fact[i] = i == 0 ? 1 : i * fact[i-1] % mod;
    invFact[i] = inverse(fact[i]);
  }
}

int main() {
  int N, M, n;
  cin >> N >> M;
  n = N > 0 ? N : -N;
  int k = numberPF(n);
  calcInvFact();
  long long ans = 1;
  for (int i = 0; i < k; i++) ans = ans * combination(p[i] + M - 1, p[i]) % mod;
  ans = ans * power(2, M - 1) % mod;
  cout << ans << endl;
  return 0;
}
