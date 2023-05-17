#include <iostream>
using namespace std;

int main() {
  int h1, h2, h3, w1, w2, w3;
  cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
  int count = 0;
  for (int n11 = 1; n11 <= min(h1, w1) - 2; n11++) {
    for (int n12 = 1; n12 <= min(h1 - n11 - 1, w2 - 2); n12++) {
      int n13 = h1 - n11 - n12;
      for (int n21 = 1; n21 <= min(h2 - 2, w1 - n11 - 1); n21++) {
        int n31 = w1 - n11 - n21;
        for (int n22 = 1; n22 <= min(h2 - n21, w2 - n12) - 1; n22++) {
          int n23 = h2 - n21 - n22;
          int n32 = w2 - n12 - n22;
          int n33 = h3 - n31 - n32;
          if (n33 > 0 && n33 == w3 - n13 - n23) count++;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}
