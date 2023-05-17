#include <iostream>
using namespace std;

int main() {
  int N;
  long long L, R, A[200001], left[200001], right[200001];
  cin >> N >> L >> R;
  for (int i = 1; i <= N; i++) cin >> A[i];
  left[0] = 0;
  right[N] = 0;
  for (int i = 1; i <= N; i++) {
    left[i] = min(left[i-1] + A[i], L * i);
    right[N-i] = min(right[N-i+1] + A[N-i+1], R * i);
  }
  long long ans = 3e14;
  for (int i = 0; i <= N; i++) ans = min(ans, left[i] + right[i]);
  cout << ans << endl;
  return 0;
}
