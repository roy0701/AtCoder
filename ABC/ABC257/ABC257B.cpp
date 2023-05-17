#include <iostream>
using namespace std;

int main() {
  int N, K, Q, A[200], L;
  cin >> N >> K >> Q;
  for (int j = 0; j < K; j++) cin >> A[j];
  for (int i = 0; i < Q; i++) {
    cin >> L;
    L--;
    if (A[L] < N && A[L] + 1 != A[L+1]) A[L]++;
  }
  for (int j = 0; j < K - 1; j++) cout << A[j] << " ";
  cout << A[K-1] << endl;
  return 0;
}
