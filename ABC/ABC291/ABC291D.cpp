#include <iostream>
using namespace std;

int main() {
  long long modulo = 998244353;
  int N, A[200000], B[200000];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  long long ans = 0;
  long long front = 1;
  long long back = 1;
  long long newFront, newBack;
  for (int i = 1; i < N; i++) {
    if (A[i] != A[i - 1] && A[i] != B[i - 1]) {
      newFront = front + back;
    } else if (A[i] != A[i - 1]) {
      newFront = front;
    } else if (A[i] != B[i - 1]) {
      newFront = back;
    } else {
      newFront = 0;
    }
    if (B[i] != A[i - 1] && B[i] != B[i - 1]) {
      newBack = front + back;
    } else if (B[i] != A[i - 1]) {
      newBack = front;
    } else if (B[i] != B[i - 1]) {
      newBack = back;
    } else {
      newBack = 0;
    }
    front = newFront % modulo;
    back = newBack % modulo;
  }
  cout << (front + back) % modulo << endl;
  return 0;
}
