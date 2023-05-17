#include <iostream>
using namespace std;

int main() {
  int N, A[200001];
  bool called[200001];
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= N; i++) {
    called[i] = false;
  }
  int K = N;
  for (int i = 1; i <= N; i++) {
    if (!called[i] && !called[A[i]]) {
      called[A[i]] = true;
      K--;
    }
  }
  cout << K << endl;
  for (int i = 1; i <= N; i++) {
    if (!called[i]) {
      cout << i;
      K--;
      if (K == 0) {
        cout << endl;
        break;
      } else {
        cout << " ";
      }
    }
  }
  return 0;
}
