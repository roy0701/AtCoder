#include <iostream>
using namespace std;

int parent[400000];

int root(int x) {
  if (parent[x] == x) {
    return x;
  } else {
    parent[x] = root(parent[x]);
    return parent[x];
  }
}

void unite(int x, int y) {
  int rx = root(x);
  int ry = root(y);
  if (rx < ry) parent[ry] = rx;
  else if (rx > ry) parent[rx] = ry;
}

int main() {
  int M, u, v;
  long long N;
  long long size[200000];
  cin >> N >> M;
  for (int i = 0; i < N * 2; i++) parent[i] = i;
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    unite(u-1, v-1 + N);
    unite(v-1, u-1 + N);
  }
  for (int i = 0; i < N; i++) {
    if (root(i + N) == root(i)) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < N; i++) size[i] = 0;
  for (int i = 0; i < N; i++) size[root(i)]++;
  long long ans = N * (N - 1) / 2 - M;
  for (int i = 0; i < N; i++) ans -= size[i] * (size[i] - 1) / 2;
  cout << ans << endl;
  return 0;
}
