#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Edge {
  int u, v;
  double cost, time, rate;
};

int N, M, parents[10000];
Edge edges[10000];

bool operator<(const Edge& e1, const Edge& e2) noexcept {
  return e1.rate < e2.rate;
}

int root(int x) {
  if (parents[x] == x) return x;
  return parents[x] = root(parents[x]);
}

void unite(int x, int y) {
  int rootX = root(x);
  int rootY = root(y);
  if (rootX != rootY) parents[rootY] = rootX;
}

bool isPossible(double wage) {
  for (int v = 0; v < N; v++) parents[v] = v;
  for (int i = 0; i < M; i++) edges[i].rate = edges[i].cost - wage * edges[i].time;
  sort(edges, edges + M);
  double ans = 0;
  for (int i = 0; i < M; i++) {
    Edge e = edges[i];
    if (e.rate <= 0 || root(e.u) != root(e.v)) {
      unite(e.u, e.v);
      ans += e.rate;
    }
  }
  return ans <= 0;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> edges[i].u >> edges[i].v >> edges[i].cost >> edges[i].time;
  double l = 0;
  double r = 1e6;
  while (r - l > 1e-3) {
    double m = (l + r) / 2;
    if (isPossible(m)) r = m;
    else l = m;
  }
  cout << fixed << setprecision(3) << r << endl;
  return 0;
}
