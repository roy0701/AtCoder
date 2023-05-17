#include <iostream>
using namespace std;

long long B;

int digit(int n) {
  int k = 0;
  for (int m = n; m > 0; m /= 10) k++;
  return k;
}

long long power10(int n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    long long x = power10(n / 2);
    return x * x % B;
  } else {
    return power10(n - 1) * 10 % B;
  }
}

int main() {
  int N, a[10000], L[10000];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i] >> L[i];
  cin >> B;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    int l = L[i];
    long long x = a[i];
    long long p = power10(digit(x));
    while (true) {
      if (l % 2 == 1) ans = (ans * p + x) % B;
      l /= 2;
      if (l == 0) break;
      x = x * (p + 1) % B;
      p = p * p % B;
    }
  }
  cout << ans << endl;
  return 0;
}
