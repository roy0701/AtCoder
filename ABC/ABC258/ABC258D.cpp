#include <iostream>
using namespace std;

int main() {
  int N;
  long long X, A[200000], B[200000];
  cin >> N >> X;
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  long long time = A[0] + B[0];
  long long ans = time + B[0] * (X - 1);
  for (int i = 1; i < N && i + 1 <= X; i++) {
    time += A[i] + B[i];
    ans = min(ans, time + B[i] * (X - i - 1));
  }
  cout << ans << endl;
  return 0;
}
