#include <iostream>
using namespace std;

int euclid(int n, int m) {
  if (m == 0) return n;
  else return euclid(m, n % m);
}

int main() {
  int N, K, A[100000];
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  int m = A[0];
  int gcd = A[0];
  for (int i = 1; i < N; i++) {
    m = max(m, A[i]);
    gcd = A[i] >= gcd ? euclid(A[i], gcd) : euclid(gcd, A[i]);
  }
  if (K <= m && K % gcd == 0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}
