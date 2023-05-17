#include <iostream>
using namespace std;

long long A, X, M;

long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    long long y = power(x, n / 2);
    return y * y % M;
  } else {
    return x * power(x, n - 1) % M;
  }
}

long long sum(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    long long y = sum(x, n / 2 - 1);
    long long z = power(x, n / 2);
    return (y + (z * y) % M + (z * z) % M) % M;
  } else {
    return (sum(x, n - 1) + power(x, n)) % M;
  }
}

int main() {
  cin >> A >> X >> M;
  if (M == 1) {
    cout << 0 << endl;
  } else {
    cout << sum(A % M, X - 1) << endl;
  }
  return 0;
}
