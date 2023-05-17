#include <iostream>
using namespace std;

long long gcd(long long x, long long y) {
  if (x < y) {
    long long tmp = x;
    x = y;
    y = tmp;
  }
  while (y > 0) {
    long long tmp = x % y;
    x = y;
    y = tmp;
  }
  return x;
}

bool isPrime(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  long long K;
  cin >> K;
  if (isPrime(K)) {
    cout << K << endl;
    return 0;
  }
  long long N = 1;
  long long ans;
  while (true) {
    long long g = gcd(K, N);
    if (g > 1) {
      K /= g;
      if (K == 1) {
        ans = N;
        break;
      } else if (K > N && isPrime(K)) {
        ans = K;
        break;
      }
    }
    N++;
  }
  cout << ans << endl;
  return 0;
}
