#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  long long D;
  cin >> N >> M >> D;
  vector<long long> A(N, 0), B(M, 0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int j = 0; j < M; j++) {
    cin >> B[j];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int i = N - 1;
  int j = M - 1;
  while (i >= 0 && j >= 0) {
    if (abs(A[i] - B[j]) <= D) {
      cout << A[i] + B[j] << endl;
      return 0;
    } else if (A[i] > B[j]) {
      i--;
    } else {
      j--;
    }
  }
  cout << "-1" << endl;
  return 0;
}
