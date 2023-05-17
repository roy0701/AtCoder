#include <iostream>
using namespace std;

int main() {
  int R, C, A[2][2];
  cin >> R >> C;
  cin >> A[0][0] >> A[0][1];
  cin >> A[1][0] >> A[1][1];
  cout << A[R-1][C-1] << endl;
  return 0;
}
