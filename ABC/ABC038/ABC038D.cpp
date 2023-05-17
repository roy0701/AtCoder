#include <iostream>
#include <algorithm>
using namespace std;

int last[100000];

struct Box {
  int w, h;
};

bool operator<(const Box& b1, const Box& b2) noexcept {
  return b1.w < b2.w || (b1.w == b2.w && b1.h > b2.h);
}

int binarySearch(int x, int l, int h) {
  if (l == h) return h;
  int m = (l + h) / 2;
  if (x < last[m]) return binarySearch(x, l, m);
  else if (x > last[m]) return binarySearch(x, m + 1, h);
  else return m;
}

int main() {
  int N;
  Box boxes[100000];
  cin >> N;
  for (int i = 0; i < N; i++) {
    int w, h;
    cin >> w >> h;
    boxes[i] = Box{w, h};
  }
  sort(boxes, boxes + N);
  last[0] = boxes[0].h;
  int ans = 1;
  for (int i = 1; i < N; i++) {
    int h = boxes[i].h;
    if (h <= last[0]) {
      last[0] = h;
    } else if (h > last[ans - 1]) {
      last[ans] = h;
      ans++;
    } else {
      last[binarySearch(h, 1, ans - 1)] = h;
    }
  }
  cout << ans << endl;
  return 0;
}
