#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#define MAX 1000000

vector<vector<int>> edges(200001, vector<int>());
vector<bool> visited(200001, false);

int bfs(int u, int ans) {
  visited[u] = true;
  int res = ans;
  for (int v : edges[u]) {
    if (!visited[v]) {
      res = bfs(v, res);
      if (res >= MAX) {
        return MAX;
      }
    }
  }
  visited[u] = false;
  return res + 1;
}

int main() {
  int N, M, u, v;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  cout << min(bfs(1, 0), MAX) << endl;
  return 0;
}
