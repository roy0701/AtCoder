#include <iostream>
using namespace std;

int main() {
  int N;
  long long T, A[100000];
  cin >> N >> T;
  for (int i = 0; i < N; i++) cin >> A[i];
  long long sum = 0;
  for (int i = 0; i < N; i++) sum += A[i];
  long long time = T % sum;
  sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i];
    if (time <= sum) {
      cout << i+1 << " " << time - sum + A[i] << endl;
      return 0;
    }
  }
  return 0;
}
