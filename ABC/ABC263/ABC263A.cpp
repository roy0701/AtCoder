#include <iostream>
using namespace std;

int main() {
  int A;
  cin >> A;
  int x = A;
  int xcnt = 1;
  int y = 0;
  int ycnt = 0;
  for (int i = 1; i < 5; i++) {
    cin >> A;
    if (A == x) {
      xcnt++;
    } else if (A == y) {
      ycnt++;
    } else if (y == 0) {
      y = A;
      ycnt++;
    }
  }
  if ((xcnt == 3 && ycnt == 2) || (xcnt == 2 && ycnt == 3)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
