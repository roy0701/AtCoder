#include <iostream>
using namespace std;

int N;
bool edges[100][100];
bool visited[100];

bool dfs(int p, int u) {
  if (visited[u]) return false;
  visited[u] = true;
  bool flag = true;
  for (int v = 0; v < N; v++) {
    if (edges[u][v] && v != p) {
      if (!dfs(u, v)) flag = false;
    }
  }
  return flag;
}

int main() {
  int M, u, v;
  cin >> N >> M;
  for (u = 0; u < N; u++) {
    for (v = 0; v < N; v++) {
      edges[u][v] = false;
    }
  }
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    edges[u-1][v-1] = true;
    edges[v-1][u-1] = true;
  }
  for (u = 0; u < N; u++) {
    visited[u] = false;
  }
  int count = 0;
  for (u = 0; u < N; u++) {
    if (!visited[u]) {
      visited[u] = true;
      bool flag = true;
      for (v = u + 1; v < N; v++) {
        if (edges[u][v]) {
          if (!dfs(u, v)) flag = false;
        }
      }
      if (flag) count++;
    }
  }
  cout << count << endl;
  return 0;
}
