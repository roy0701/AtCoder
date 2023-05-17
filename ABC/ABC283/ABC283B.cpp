#include <iostream>
using namespace std;

int main() {
  int N, A[100001], Q, q, k, x;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> q;
    if (q == 1) {
      cin >> k >> x;
      A[k] = x;
    } else if (q == 2) {
      cin >> k;
      cout << A[k] << endl;
    }
  }
  return 0;
}
