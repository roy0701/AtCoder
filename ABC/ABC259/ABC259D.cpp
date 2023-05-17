#include <iostream>
#include <vector>
using namespace std;

long long dist2(long long x1, long long y1, long long x2, long long y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
  int N;
  long long sx, sy, tx, ty, x[3000], y[3000], r[3000];
  bool added[3000];
  cin >> N;
  cin >> sx >> sy >> tx >> ty;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> r[i];
    added[i] = false;
  }
  vector<int> circles = {};
  for (int i = 0; i < N; i++) {
    if (dist2(sx, sy, x[i], y[i]) == r[i] * r[i]) circles.push_back(i);
  }
  for (int j = 0; j < circles.size(); j++) {
    int i = circles[j];
    if (dist2(tx, ty, x[i], y[i]) == r[i] * r[i]) {
      cout << "Yes" << endl;
      return 0;
    }
    for (int k = 0; k < N; k++) {
      long long d2 = dist2(x[k], y[k], x[i], y[i]);
      if (!added[k] && (r[k] - r[i]) * (r[k] - r[i]) <= d2 && d2 <= (r[k] + r[i]) * (r[k] + r[i])) {
        circles.push_back(k);
        added[k] = true;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
