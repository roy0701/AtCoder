#include <iostream>
#include <algorithm>
using namespace std;

int A[200000];

int binarySearch(int x, int l, int r) {
  if (l + 1 == r) return l;
  int m = (l + r) / 2;
  if (x == A[m]) return m;
  else if (x < A[m]) return binarySearch(x, l, m);
  else return binarySearch(x, m, r);
}

int main() {
  int N, Q;
  long long x, left[200000], right[200000];
  cin >> N >> Q;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  left[0] = A[0];
  right[N-1] = A[N-1];
  for (int i = 1; i < N; i++) {
    left[i] = left[i-1] + A[i];
    right[N-i-1] = right[N-i] + A[N-i-1];
  }
  for (int j = 0; j < Q; j++) {
    cin >> x;
    long long ans;
    if (x <= A[0]) {
      ans = right[0] - x * N;
    } else if (x >= A[N-1]) {
      ans = x * N - left[N-1];
    } else {
      long long k = binarySearch(x, 0, N-1);
      ans = x * (k+1) - left[k] + right[k+1] - x * (N-k-1);
    }
    cout << ans << endl;
  }
  return 0;
}
