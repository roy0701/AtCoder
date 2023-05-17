#include <iostream>
using namespace std;

int main() {
  int N, M, A[100], B[100];
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int j = 0; j < M; j++) {
    cin >> B[j];
  }
  int ans = 0;
  for (int j = 0; j < M; j++) {
    ans += A[B[j] - 1];
  }
  cout << ans << endl;
  return 0;
}
