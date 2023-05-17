#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, K, J, j, k;
  cin >> N >> K;
  if (N % K == 0) J = N / K;
  else J = N / K + 1;
  int a[K][J];
  for (int i = 0; i < N; i++) {
    k = i % K;
    j = i / K;
    cin >> a[k][j];
  }
  for (k += 1; k < K; k++) a[k][j] = 1000000001;
  for (k = 0; k < K; k++) sort(a[k], a[k] + J);
  for (int i = 0; i < N - 1; i++) {
    k = i % K;
    j = i / K;
    if (k < K - 1) {
      if (a[k][j] > a[k+1][j]) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (a[k][j] > a[0][j+1]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
