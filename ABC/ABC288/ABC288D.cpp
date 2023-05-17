#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K, Q, l, r;
  cin >> N >> K;
  vector<int> A(N);
  vector<vector<long long>> sum(K, vector<long long>(N + 1));
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int j = 0; j < K; j++) {
    for (int i = 0; i < N; i++) {
      sum[j][i + 1] = sum[j][i];
      if (i % K == j) sum[j][i + 1] += A[i];
    }
  }
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> l >> r;
    long long x = sum[0][r] - sum[0][l - 1];
    bool ans = true;
    for (int j = 1; j < K; j++) {
      if (sum[j][r] - sum[j][l - 1] != x) {
        ans = false;
        break;
      }
    }
    cout << (ans ? "Yes" : "No") << endl;
  }
  return 0;
}
