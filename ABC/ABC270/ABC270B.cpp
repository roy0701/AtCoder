#include <iostream>
using namespace std;

int main() {
  int X, Y, Z, ans;
  cin >> X >> Y >> Z;
  if (X > 0) {
    if (X < Y || Y < 0) ans = abs(X);
    else if (Z < Y) ans = abs(Z) + abs(X - Z);
    else ans = -1;
  } else {
    if (Y < X || Y > 0) ans = abs(X);
    else if (Y < Z) ans = abs(Z) + abs(X - Z);
    else ans = -1;
  }
  cout << ans << endl;
  return 0;
}
