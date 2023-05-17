#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
  int N, M, u, v;
  set<int> edges[200001];
  bool visited[200001];
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    edges[u].insert(v);
  }
  int ans = 0;
  for (u = 1; u <= N; u++) {
    for (int v = 1; v <= N; v++) {
      visited[v] = false;
    }
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int w : edges[v]) {
        if (!visited[w]) {
          visited[w] = true;
          q.push(w);
        }
      }
    }
    visited[u] = false;
    for (int v = 1; v <= N; v++) {
      if (visited[v] && !edges[u].count(v)) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
