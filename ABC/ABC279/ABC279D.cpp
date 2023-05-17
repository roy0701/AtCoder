#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long long A, B;

double time(long long g) {
  return (double) B * (double) (g-1) + (double) A / sqrt(g);
}

double binsearch(long long l, long long r) {
  if (l >= r) return min(time(l), time(r));
  long long m = (l + r) / 2;
  double t1 = time(m);
  double t2 = time(m+1);
  if (t1 > t2) return binsearch(m+1, r);
  else return binsearch(l, m);
}

int main() {
  cin >> A >> B;
  double ans = binsearch(1, A / B + 1);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
