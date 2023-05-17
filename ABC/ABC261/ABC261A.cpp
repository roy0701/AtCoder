#include <iostream>
using namespace std;

int main() {
  int L1, R1, L2, R2, ans;
  cin >> L1 >> R1 >> L2 >> R2;
  if (L2 < L1) {
    int tmp = L1;
    L1 = L2;
    L2 = tmp;
    tmp = R1;
    R1 = R2;
    R2 = tmp;
  }
  if (R1 < L2) ans = 0;
  else if (L2 <= R1 && R1 <= R2) ans = R1 - L2;
  else ans = R2 - L2;
  cout << ans << endl;
  return 0;
}
