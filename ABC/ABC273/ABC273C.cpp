#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, A[200000], cnt[200000];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  int now = 0;
  int j = -1;
  for (int i = 0; i < N; i++) {
    if (A[i] > now) {
      j++;
      cnt[j] = 1;
      now = A[i];
    } else {
      cnt[j]++;
    }
  }
  for (int K = 0; K < N; K++) {
    if (j >= K) cout << cnt[j-K] << endl;
    else cout << 0 << endl;
  }
  return 0;
}
