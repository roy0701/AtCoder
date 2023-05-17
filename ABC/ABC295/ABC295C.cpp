#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, A[500000];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);
  int ans = 0;
  int prev = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] == prev) {
      ans++;
      prev = 0;
    } else {
      prev = A[i];
    }
  }
  cout << ans << endl;
  return 0;
}
