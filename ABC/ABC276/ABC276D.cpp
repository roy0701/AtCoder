#include <iostream>
using namespace std;

int gcd(int x, int y) {
  if (y == 0) return x;
  else return gcd(y, x % y);
}

int countDivision(int x) {
  if (x == 1) return 0;
  else if (x % 2 == 0) {
    int res = countDivision(x / 2);
    return res < 0 ? res : res + 1;
  }
  else if (x % 3 == 0) {
    int res = countDivision(x / 3);
    return res < 0 ? res : res + 1;
  }
  else return -1;
}

int main() {
  int N, a[1000];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  int ans = 0;
  int x = a[0];
  for (int i = 1; i < N; i++) {
    int y = a[i];
    int g = x > y ? gcd(x, y) : gcd(y, x);
    int cx = countDivision(x / g);
    int cy = countDivision(y / g);
    if (cx < 0 || cy < 0) {
      cout << "-1" << endl;
      return 0;
    }
    ans += cx * i + cy;
    x = g;
  }
  cout << ans << endl;
  return 0;
}
