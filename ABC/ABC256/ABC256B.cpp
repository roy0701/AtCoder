#include <iostream>
using namespace std;

int main() {
  int N, A[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  int P = 0;
  int state = 0;
  for (int i = 0; i < N; i++) {
    state++;
    state <<= A[i];
    int k = state / 16;
    for (int j = 0; k > 0; j++) {
      P += k % 2;
      k >>= 1;
    }
    state %= 16;
  }
  cout << P << endl;
  return 0;
}
