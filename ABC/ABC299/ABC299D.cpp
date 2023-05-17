#include <iostream>
using namespace std;

int main() {
  int N, S;
  cin >> N;
  int l = 1;
  int r = N;
  while (r - l > 1) {
    int m = (l + r) / 2;
    cout << "? " << m << endl;
    cin >> S;
    if (S == 0) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << "! " << l << endl;
  return 0;
}
