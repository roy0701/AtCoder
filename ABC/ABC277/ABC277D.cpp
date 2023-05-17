#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, M, A[200000];
  long long sum = 0;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
  }
  sort(A, A + N);
  long long ans = sum;
  long long subsum = A[0];
  int start = 0;
  for (int i = 1; i < N; i++) {
    if (A[i] == A[i-1] || A[i] == A[i-1] + 1) {
      subsum += A[i];
    } else {
      ans = min(ans, sum - subsum);
      subsum = A[i];
      start = i;
    }
  }
  if (A[0] == 0 && A[N-1] == M-1) {
    for (int i = 1; i < start; i++) {
      if (A[i] == A[i-1] || A[i] == A[i-1] + 1) {
        subsum += A[i];
      } else {
        break;
      }
    }
  }
  ans = min(ans, sum - subsum);
  cout << ans << endl;
  return 0;
}
