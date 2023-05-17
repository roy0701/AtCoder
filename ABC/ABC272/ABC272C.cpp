#include <iostream>
using namespace std;

int main() {
  int N, A[200000];
  cin >> N;
  int evenCount = 0;
  int oddCount = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] % 2 == 0) evenCount++;
    else oddCount++;
  }
  int ans = 0;
  if (evenCount < 2 && oddCount < 2) {
    ans = -1;
  } else {
    if (evenCount >= 2) {
      int m1 = -1;
      int m2 = -1;
      for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0) {
          if (A[i] > m1) {
            m2 = m1;
            m1 = A[i];
          } else if (A[i] > m2) {
            m2 = A[i];
          }
        }
      }
      ans = max(ans, m1 + m2);
    }
    if (oddCount >= 2) {
      int m1 = -1;
      int m2 = -1;
      for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 1) {
          if (A[i] > m1) {
            m2 = m1;
            m1 = A[i];
          } else if (A[i] > m2) {
            m2 = A[i];
          }
        }
      }
      ans = max(ans, m1 + m2);
    }
  }
  cout << ans << endl;
  return 0;
}
