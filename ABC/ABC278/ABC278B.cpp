#include <iostream>
using namespace std;

int main() {
  int H, M;
  cin >> H >> M;
  while (true) {
    if (M >= 60) {
      M -= 60;
      H++;
    }
    if (H >= 24) H -= 24;
    int A = H / 10;
    int B = H % 10;
    int C = M / 10;
    int D = M % 10;
    if (A < 2) {
      if (B < 6) {
        cout << A * 10 + B << " " << C * 10 + D << endl;
        break;
      } else {
        H++;
        M = 0;
      }
    } else {
      if (B < 6 && C < 4) {
        cout << A * 10 + B << " " << C * 10 + D << endl;
        break;
      } else {
        H++;
        M = 0;
      }
    }
  }
  return 0;
}
