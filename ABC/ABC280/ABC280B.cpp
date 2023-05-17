#include <iostream>
using namespace std;

int main() {
  int N, S[10];
  long long A[10];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> S[i];
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    A[i] = S[i] - sum;
    cout << A[i];
    sum += A[i];
    if (i < N-1) cout << " ";
    else cout << endl;
  }
  return 0;
}
