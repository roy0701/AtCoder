#include <iostream>
using namespace std;

int main() {
  int N, A[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  int sum = 0;
  for (int i = 0; i < N; i++) sum += A[i];
  cout << sum << endl;
  return 0;
}
