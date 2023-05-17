#include <iostream>
using namespace std;

int main() {
  int N, C, T[200000], A[200000], ans[200000], func[2], f[2];
  cin >> N >> C;
  for (int i = 0; i < N; i++) cin >> T[i] >> A[i];
  for (int i = 0; i < N; i++) ans[i] = 0;
  for (int k = 0; k < 30; k++) {
    func[0] = 0;
    func[1] = 1;
    int c = (C >> k) & 1;
    for (int i = 0; i < N; i++) {
      int a = (A[i] >> k) & 1;
      if (T[i] == 1) {
        f[0] = 0 & a;
        f[1] = 1 & a;
      } else if (T[i] == 2) {
        f[0] = 0 | a;
        f[1] = 1 | a;
      } else {
        f[0] = 0 ^ a;
        f[1] = 1 ^ a;
      }
      func[0] = f[func[0]];
      func[1] = f[func[1]];
      c = func[c];
      ans[i] = ans[i] | (c << k);
    }
  }
  for (int i = 0; i < N; i++) cout << ans[i] << endl;
  return 0;
}
