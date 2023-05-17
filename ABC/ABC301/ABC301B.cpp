#include <iostream>
using namespace std;

int main() {
  int N, A[100];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cout << A[0];
  for (int i = 0; i < N - 1; i++) {
    if (A[i] < A[i + 1]) {
      for (int j = A[i] + 1; j <= A[i + 1]; j++) {
        cout << " " << j;
      }
    } else if (A[i] > A[i + 1]) {
      for (int j = A[i] - 1; j >= A[i + 1]; j--) {
        cout << " " << j;
      }
    }
  }
  cout << endl;
  return 0;
}
