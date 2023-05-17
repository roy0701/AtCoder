#include <iostream>
using namespace std;

int main() {
  int N, M, X, T, D;
  cin >> N >> M >> X >> T >> D;
  int ans = M >= X ? T : T - (X - M) * D;
  cout << ans << endl;
  return 0;
}
