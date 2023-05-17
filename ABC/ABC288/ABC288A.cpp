#include <iostream>
using namespace std;

int main() {
  int N;
  long long A[1000], B[1000];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  for (int i = 0; i < N; i++) cout << A[i] + B[i] << endl;
  return 0;
}
