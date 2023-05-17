#include <iostream>
using namespace std;

long long gcd(long long x, long long y) {
  if (x < y) {
    return gcd(y, x);
  } else if (y == 0) {
    return x;
  } else {
    return gcd(y, x % y);
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    long long N, D, K;
    cin >> N >> D >> K;
    long long g = gcd(N, D);
    cout << (D * (K - 1) + (K - 1) * g / N) % N << endl;
  }
  return 0;
}
