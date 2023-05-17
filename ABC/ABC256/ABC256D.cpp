#include <iostream>
#include <algorithm>
using namespace std;

struct Interval {
  int L, R;
};

bool operator<(const Interval& i1, const Interval& i2) noexcept {
  return i1.L < i2.L || (i1.L == i2.L && i1.R < i2.R);
}

int main() {
  int N, L, R;
  Interval itv[200000];
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> L >> R;
    itv[i] = Interval{L, R};
  }
  sort(itv, itv + N);
  int X = itv[0].L;
  int Y = itv[0].R;
  for (int i = 1; i < N; i++) {
    if (itv[i].L > Y) {
      cout << X << " " << Y << endl;
      X = itv[i].L;
      Y = itv[i].R;
    } else {
      Y = max(Y, itv[i].R);
    }
  }
  cout << X << " " << Y << endl;
  return 0;
}
