#include <iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int ans = 0;
  if (A % 2 == 1 || B % 2 == 1) ans += 1;
  if ((A / 2) % 2 == 1 || (B / 2) % 2 == 1) ans += 2;
  if (A / 4 == 1 || B / 4 == 1) ans += 4;
  cout << ans << endl;
  return 0;
}
