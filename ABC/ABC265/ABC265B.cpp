#include <iostream>
using namespace std;

int main() {
  int N, M, T, A[100000], X, Y, B[100000];
  cin >> N >> M >> T;
  for (int i = 0; i < N - 1; i++) {
    cin >> A[i];
    B[i] = 0;
  }
  for (int j = 0; j < M; j++) {
    cin >> X >> Y;
    B[X-2] = Y;
  }
  long long t = T;
  for (int i = 0; i < N - 1; i++) {
    t -= A[i];
    if (t <= 0) {
      cout << "No" << endl;
      return 0;
    }
    t += B[i];
  }
  cout << "Yes" << endl;
  return 0;
}
