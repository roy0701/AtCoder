#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, u, v;
  vector<int> edges[200001];
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  int prev = 0;
  int now = 0;
  for (int u = 1; u <= N; u++) {
    if (edges[u].size() == 1) {
      prev = u;
      now = edges[u][0];
      break;
    }
  }
  if (now == 0) {
    cout << "No" << endl;
    return 0;
  }
  for (int k = 2; k < N; k++) {
    if (edges[now].size() != 2) {
      cout << "No" << endl;
      return 0;
    }
    if (edges[now][0] == prev) {
      prev = now;
      now = edges[now][1];
    } else {
      prev = now;
      now = edges[now][0];
    }
  }
  if (edges[now].size() == 1) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
