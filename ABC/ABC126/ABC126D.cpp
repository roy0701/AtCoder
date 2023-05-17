#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> edges[100000];
int color[100000];

void dfs(int u) {
  for (auto [v, w] : edges[u]) {
    if (color[v] < 0) {
      if (w % 2 == 0) color[v] = color[u];
      else color[v] = !color[u];
      dfs(v);
    }
  }
}

int main() {
  int N, u, v, w;
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    cin >> u >> v >> w;
    edges[u-1].push_back({v-1, w});
    edges[v-1].push_back({u-1, w});
  }
  color[0] = 0;
  for (int i = 1; i < N; i++) color[i] = -1;
  dfs(0);
  for (int i = 0; i < N; i++) cout << color[i] << endl;
  return 0;
}
