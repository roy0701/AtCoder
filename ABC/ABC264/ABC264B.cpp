#include <iostream>
using namespace std;

int main() {
  int R, C;
  cin >> R >> C;
  int r = min(R, 16 - R);
  int c = min(C, 16 - C);
  bool isBlack = r < c ? r % 2 : c % 2;
  string ans = isBlack ? "black" : "white";
  cout << ans << endl;
  return 0;
}
