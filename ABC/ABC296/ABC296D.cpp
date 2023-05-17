#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;
  if (N >= M) {
    cout << M << endl;
    return 0;
  }
  long long rM = sqrt(M) + 1;
  long long ans = -1;
  for (long long a = 1; a <= min(N, rM); a++) {
    long long b = M / a;
    if (b <= N && a * b == M) {
      ans = M;
      break;
    }
    b++;
    long long X = a * b;
    if (b <= N && X >= M) {
      ans = ans < 0 ? X : min(ans, X);
    }
  }
  cout << ans << endl;
  return 0;
}
