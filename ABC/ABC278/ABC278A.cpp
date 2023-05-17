#include <iostream>
using namespace std;

int main() {
  int N, K, A[100];
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  if (K >= N) {
    for (int i = 0; i < N - 1; i++) cout << "0 ";
    cout << "0" << endl;
  } else {
    for (int i = K; i < N; i++) cout << A[i] << " ";
    for (int i = 0; i < K - 1; i++) cout << "0 ";
    cout << "0" << endl;
  }
  return 0;
}
