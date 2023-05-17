#include <iostream>
using namespace std;

int main() {
  string S[10];
  for (int i = 0; i < 10; i++) cin >> S[i];
  int A = 0;
  int C = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (S[i][j] == '#') {
        A = i + 1;
        C = j + 1;
        break;
      }
    }
    if (A > 0) break;
  }
  int B = 0;
  int D = 0;
  for (int i = 9; i >= 0; i--) {
    for (int j = 9; j >= 0; j--) {
      if (S[i][j] == '#') {
        B = i + 1;
        D = j + 1;
        break;
      }
    }
    if (B > 0) break;
  }
  cout << A << " " << B << endl;
  cout << C << " " << D << endl;
  return 0;
}
