#include <iostream>
using namespace std;

bool ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) > 0;
}

int main() {
  int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
  cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
  bool ans = ccw(Ax, Ay, Bx, By, Cx, Cy) && ccw(Bx, By, Cx, Cy, Dx, Dy) && ccw(Cx, Cy, Dx, Dy, Ax, Ay) && ccw(Dx, Dy, Ax, Ay, Bx, By);
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
