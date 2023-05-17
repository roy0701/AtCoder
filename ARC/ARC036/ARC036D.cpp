#include <iostream>
using namespace std;

int N, parents[200000];

int root(int x) {
  if (parents[x] == x) return x;
  return parents[x] = root(parents[x]);
}

void connect(int x, int y) {
  if (x != y) parents[y] = x;
}

void unite(int x, int y, bool even) {
  if (even) {
    connect(root(x), root(y));
    connect(root(x + N), root(y + N));
  } else {
    connect(root(x), root(y + N));
    connect(root(x + N), root(y));
  }
}

int main() {
  int Q, w, x, y, z;
  cin >> N >> Q;
  for (x = 0; x < 2 * N; x++) parents[x] = x;
  for (int i = 0; i < Q; i++) {
    cin >> w >> x >> y >> z;
    x--;
    y--;
    if (w == 1) {
      unite(x, y, z % 2 == 0);
    } else {
      string ans = root(x) == root(y) ? "YES" : "NO";
      cout << ans << endl;
    }
  }
  return 0;
}
