#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parents[100000];

int root(int x) {
  if (parents[x] == x) return x;
  return parents[x] = root(parents[x]);
}

void unite(int x, int y) {
  parents[y] = x;
}

int main() {
  int N, x, y;
  vector<pair<int,int>> xs, ys;
  vector<tuple<long long, int, int>> edges;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    xs.emplace_back(x, i);
    ys.emplace_back(y, i);
    parents[i] = i;
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  for (int i = 0; i < N - 1; i++) {
    auto [x1, u1] = xs[i];
    auto [x2, u2] = xs[i+1];
    edges.emplace_back(x2 - x1, u1, u2);
    auto [y1, v1] = ys[i];
    auto [y2, v2] = ys[i+1];
    edges.emplace_back(y2 - y1, v1, v2);
  }
  sort(edges.begin(), edges.end());
  long long ans = 0;
  int count = 0;
  int k = 0;
  while (count < N - 1) {
    auto [cost, i, j] = edges[k];
    int rootI = root(i);
    int rootJ = root(j);
    if (rootI != rootJ) {
      unite(rootI, rootJ);
      ans += cost;
      count++;
    }
    k++;
  }
  cout << ans << endl;
  return 0;
}
