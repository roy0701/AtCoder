#include <iostream>
using namespace std;

int main() {
  int N, T;
  cin >> N;
  int l = 1;
  int r = N;
  while (l < r) {
    int m = (l + r) / 2;
    cout << "? " << l << " " << m << " " << 1 << " " << N << endl;
    cin >> T;
    if (T == -1) return 0;
    if (T == m - l + 1) l = m + 1;
    else r = m;
  }
  int X = l;
  l = 1;
  r = N;
  while (l < r) {
    int m = (l + r) / 2;
    cout << "? " << 1 << " " << N << " " << l << " " << m << endl;
    cin >> T;
    if (T == -1) return 0;
    if (T == m - l + 1) l = m + 1;
    else r = m;
  }
  int Y = l;
  cout << "! " << X << " " << Y << endl;
  return 0;
}
