#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, K, A[300000];
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);
  if (A[0] > 0) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i < N; i++) {
    if (A[i] > A[i - 1] + 1) {
      cout << min(A[i - 1] + 1, K) << endl;
      return 0;
    }
  }
  cout << min(A[N - 1] + 1, K) << endl;
  return 0;
}
