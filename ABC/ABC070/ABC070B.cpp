#include <iostream>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int sec = min(B, D) - max(A, C);
  if (sec < 0) sec = 0;
  cout << sec << endl;
  return 0;
}
