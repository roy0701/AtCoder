#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M, u, v;
  cin >> N >> M;
  vector<vector<int>> edges(N + 1, vector<int>());
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  vector<bool> visited(N + 1, false);
  int ans = 0;
  for (u = 1; u <= N; u++) {
    if (visited[u]) {
      continue;
    }
    visited[u] = true;
    ans++;
    queue<int> que;
    que.push(u);
    while (!que.empty()) {
      v = que.front();
      que.pop();
      for (int w : edges[v]) {
        if (!visited[w]) {
          visited[w] = true;
          que.push(w);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
