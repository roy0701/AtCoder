#include <iostream>
using namespace std;

int main() {
  long long X, A, D, N, a, d, l, ans;
  cin >> X >> A >> D >> N;
  if (D == 0) {
    ans = abs(X - A);
  } else {
    if (D > 0) {
      a = A;
      d = D;
      l = A + (N - 1) * D;
    } else {
      a = A + (N - 1) * D;
      d = -D;
      l = A;
    }
    if (X <= a) {
      ans = a - X;
    } else if (X >= l) {
      ans = X - l;
    } else {
      long long x = X - a;
      long long i = (x / d) * d;
      long long j = i + d;
      ans = min(abs(x - i), abs(x - j));
    }
  }
  cout << ans << endl;
  return 0;
}
