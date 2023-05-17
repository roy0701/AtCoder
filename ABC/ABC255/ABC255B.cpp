#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
  int N, K, A[1000], X[1000], Y[1000];
  cin >> N >> K;
  for (int k = 0; k < K; k++) {
    cin >> A[k];
    A[k]--;
  }
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
  long long max2 = 0;
  for (int i = 0; i < N; i++) {
    long long min2 = 8e10;
    for (int k = 0; k < K; k++) {
      long long xDiff = X[i] - X[A[k]];
      long long yDiff = Y[i] - Y[A[k]];
      long long dist2 = xDiff * xDiff + yDiff * yDiff;
      min2 = min(min2, dist2);
    }
    max2 = max(max2, min2);
  }
  cout << fixed << setprecision(6) << sqrt(max2) << endl;
  return 0;
}
