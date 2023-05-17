#include <iostream>
using namespace std;

int p[10000];
const long long mod = 1e9 + 7;

int numberPF(int n) {
  int m = n;
  int k = 0;
  for (int i = 2; m > 1; i++) {
    if (m % i == 0) {
      while (m % i == 0) {
        m /= i;
        p[k]++;
      }
      k++;
    }
  }
  return k;
}

long long fact(int n) {
  long long ans = 1;
  for (int i = 2; i <= n; i++) ans = ans * i % mod;
  return ans;
}

long long permutation(int n, int r) {
  long long ans = 1;
  for (int i = 0; i < r; i++) ans = ans * (n - i) % mod;
  return ans;
}

long long power(int n, int m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    long long x = power(n, m / 2);
    return x * x % mod;
  } else {
    return n * power(n, m - 1) % mod;
  }
}

long long inverse(int n) {
  return power(n, mod - 2);
}

long long comb(int n, int r) {
  return permutation(n, r) * inverse(fact(r)) % mod;
}

int main() {
  int N, M;
  cin >> N >> M;
  int k = numberPF(M);
  long long ans = 1;
  for (int i = 0; i < k; i++) ans = ans * comb(p[i] + N - 1, p[i]) % mod;
  cout << ans << endl;
  return 0;
}
