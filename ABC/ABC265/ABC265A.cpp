#include <iostream>
using namespace std;

int main() {
  int X, Y, N;
  cin >> X >> Y >> N;
  int ans = Y > X * 3 ? X * N : Y * (N / 3) + X * (N % 3);
  cout << ans << endl;
  return 0;
}
