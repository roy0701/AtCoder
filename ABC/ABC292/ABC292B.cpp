#include <iostream>
using namespace std;

int main() {
  int N, Q, c, x;
  bool yellow[101], red[101];
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    yellow[i] = false;
    red[i] = false;
  }
  for (int q = 0; q < Q; q++) {
    cin >> c >> x;
    if (c == 1) {
      if (yellow[x]) {
        red[x] = true;
      } else {
        yellow[x] = true;
      }
    } else if (c == 2) {
      red[x] = true;
    } else if (c == 3) {
      cout << (red[x] ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
