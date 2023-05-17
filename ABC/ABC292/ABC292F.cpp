#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int A, B;
double pi = 3.141592653589793;

bool test(double x) {
  if (x < A) {
    return true;
  }
  double theta = acos(A / x);
  if (theta > pi / 6) {
    return false;
  }
  if (x * sin(theta) + x * cos(pi / 6 + theta) < B) {
    return true;
  } else {
    return false;
  }
}

double binarySearch(double l, double r) {
  if (r - l < 1e-12) {
    return l;
  }
  double m = (l + r) / 2;
  if (test(m)) {
    return binarySearch(m, r);
  } else {
    return binarySearch(l, m);
  }
}

int main() {
  cin >> A >> B;
  if (A > B) {
    int tmp = A;
    A = B;
    B = tmp;
  }
  cout << setprecision(15) << binarySearch(0, 10000) << endl;
  return 0;
}
