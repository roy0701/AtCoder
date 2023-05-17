#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  double a, b, d;
  cin >> a >> b >> d;
  double theta = d * acos(-1) / 180;
  double a1 = a * cos(theta) - b * sin(theta);
  double b1 = a * sin(theta) + b * cos(theta);
  cout << fixed << setprecision(7) << a1 << " " << b1 << endl;
  return 0;
}
