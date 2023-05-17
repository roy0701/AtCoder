#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
  int x, y;
};

bool operator<(const Point& p1, const Point& p2) noexcept {
  return p1.x > p2.x;
}

int main() {
  int N;
  Point red[100], blue[100];
  bool paired[100];
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    red[i] = Point{a, b};
  }
  for (int j = 0; j < N; j++) {
    int c, d;
    cin >> c >> d;
    blue[j] = Point{c, d};
    paired[j] = false;
  }
  sort(red, red + N);
  sort(blue, blue + N);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int min = 2 * N + 1;
    int jmin = N;
    for (int j = 0; blue[j].x > red[i].x && j < N; j++) {
      if (!paired[j] && blue[j].y > red[i].y && blue[j].y < min) {
        min = blue[j].y;
        jmin = j;
      }
    }
    if (jmin < N) {
      paired[jmin] = true;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
