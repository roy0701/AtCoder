#include <iostream>
using namespace std;

int main() {
  int N, M;
  long long A[200000];
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> A[i];
  long long value = 0;
  long long sum = 0;
  for (int i = 0; i < M; i++) {
    value += (i + 1) * A[i];
    sum += A[i];
  }
  long long maxValue = value;
  for (int i = 0; i < N - M; i++) {
    value += M * A[i + M] - sum;
    sum += A[i + M] - A[i];
    maxValue = max(maxValue, value);
  }
  cout << maxValue << endl;
  return 0;
}
