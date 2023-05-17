#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  int N, M, K, u, v, a, s, dist[200001][2];
  bool switches[200001];
  map<int,map<int,vector<int>>> edges;
  int inf = 1000000000;
  cin >> N >> M >> K;
  for (u = 1; u <= N; u++) {
    dist[u][0] = inf;
    dist[u][1] = inf;
    switches[u] = false;
  }
  for (int i = 0; i < M; i++) {
    cin >> u >> v >> a;
    if (edges[u].count(a)) edges[u][a].push_back(v);
    else edges[u][a] = {v};
    if (edges[v].count(a)) edges[v][a].push_back(u);
    else edges[v][a] = {u};
  }
  for (int i = 0; i < K; i++) {
    cin >> s;
    switches[s] = true;
  }
  vector<int> vertexes = {1};
  vector<int> modes = {1};
  dist[1][1] = 0;
  for (int i = 0; i < vertexes.size(); i++) {
    u = vertexes[i];
    int m = modes[i];
    for (int j = 0; j < edges[u][m].size(); j++) {
      v = edges[u][m][j];
      if (dist[v][m] == inf) {
        vertexes.push_back(v);
        modes.push_back(m);
        dist[v][m] = dist[u][m] + 1;
      }
    }
    if (switches[u]) {
      m = 1 - m;
      for (int j = 0; j < edges[u][m].size(); j++) {
        v = edges[u][m][j];
        if (dist[v][m] == inf) {
          vertexes.push_back(v);
          modes.push_back(m);
          dist[v][m] = dist[u][1-m] + 1;
        }
      }
    }
  }
  int ans = inf;
  ans = min(min(ans, dist[N][0]), dist[N][1]);
  if (ans == inf) cout << "-1" << endl;
  else cout << ans << endl;
  return 0;
}
