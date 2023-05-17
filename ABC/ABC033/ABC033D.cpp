#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = atan2(0, -1);

struct Point {
  int x, y;
};

bool operator<(const Point& p1, const Point& p2) noexcept {
  double angle1 = atan2(p1.y, p1.x);
  double angle2 = atan2(p2.y, p2.x);
  if (angle1 < 0) angle1 += 2 * pi;
  if (angle2 < 0) angle2 += 2 * pi;
  return angle1 < angle2;
}

bool isAngleU180(Point p1, Point p2) {
  return p1.x * p2.y - p1.y * p2.x > 0;
}

bool isAngle90(Point p1, Point p2) {
  return isAngleU180(p1, p2) && p1.x * p2.x + p1.y * p2.y == 0;
}

bool isAngleU90(Point p1, Point p2) {
  return isAngleU180(p1, p2) && p1.x * p2.x + p1.y * p2.y > 0;
}

int main() {
  long long N;
  int x[2000], y[2000];
  Point p[4000];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
  long long right = 0;
  long long obtuse = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j < i) {
        p[j].x = x[j] - x[i];
        p[j].y = y[j] - y[i];
      } else if (j > i) {
        p[j-1].x = x[j] - x[i];
        p[j-1].y = y[j] - y[i];
      }
    }
    sort(p, p + (N-1));
    for (int j = 0; j < N-1; j++) {
      p[j+N-1].x = p[j].x;
      p[j+N-1].y = p[j].y;
    }
    int k = 0;
    int l = 0;
    for (int j = 0; j < N-1; j++) {
      if (k < j) k = j;
      while (isAngleU90(p[j], p[k+1])) k++;
      if (isAngle90(p[j], p[k+1])) {
        right++;
        k++;
      }
      if (l < k) l = k;
      while (isAngleU180(p[j], p[l+1])) l++;
      obtuse += l - k;
    }
  }
  long long acute = N * (N-1) * (N-2) / 6 - right - obtuse;
  cout << acute << " " << right << " " << obtuse << endl;
  return 0;
}
