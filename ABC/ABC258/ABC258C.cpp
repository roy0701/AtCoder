#include <iostream>
using namespace std;

int main() {
  int N, Q, t ,x;
  string S;
  cin >> N >> Q;
  cin >> S;
  int rot = 0;
  for (int i = 0; i < Q; i++) {
    cin >> t >> x;
    if (t == 1) {
      rot -= x;
      if (rot < 0) rot += N;
    } else if (t == 2) {
      cout << S[(x - 1 + rot) % N] << endl;
    }
  }
  return 0;
}
