#include <iostream>
using namespace std;

int parent[200001];

int root(int x) {
  if (parent[x] == x) {
    return x;
  } else {
    return parent[x] = root(parent[x]);
  }
}

void unite(int x, int y) {
  int rx = root(x);
  int ry = root(y);
  if (rx != ry) {
    parent[rx] = ry;
  }
}

bool same(int x, int y) { return root(x) == root(y); }

int main() {
  int N, M, u, v, e[200001], children[200001], edges[200001];
  cin >> N >> M;
  for (int j = 1; j <= N; j++) {
    parent[j] = j;
    e[j] = 0;
    children[j] = 0;
    edges[j] = 0;
  }
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    unite(u, v);
    e[u]++;
  }
  for (int j = 1; j <= N; j++) {
    int r = root(j);
    children[r]++;
    edges[r] += e[j];
  }
  bool ans = true;
  for (int j = 1; j <= N; j++) {
    if (root(j) == j) {
      if (children[j] != edges[j]) {
        ans = false;
        break;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
