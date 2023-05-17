#include <iostream>
using namespace std;

int main() {
  int A[5];
  for (int i = 0; i < 5; i++) cin >> A[i];
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    bool flag = true;
    for (int j = 0; j < i; j++) {
      if (A[i] == A[j]) {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
  }
  cout << ans << endl;
  return 0;
}
