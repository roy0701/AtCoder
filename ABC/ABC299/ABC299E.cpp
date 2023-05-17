#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M, u, v, K, p[2000], d[2000];
  cin >> N >> M;
  vector<int> edges[2001], dist[2001];
  bool black[2001];
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int j = 1; j <= N; j++) {
    black[j] = true;
    for (int k = 0; k <= N; k++) {
      dist[j].push_back(-1);
    }
    dist[j][j] = 0;
    queue<int> q;
    q.push(j);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int next : edges[now]) {
        if (dist[j][next] < 0) {
          dist[j][next] = dist[j][now] + 1;
          q.push(next);
        }
      }
    }
  }
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> p[i] >> d[i];
    for (int k = 1; k <= N; k++) {
      if (dist[p[i]][k] < d[i]) {
        black[k] = false;
      }
    }
  }
  for (int i = 0; i < K; i++) {
    bool ok = false;
    for (int k = 1; k <= N; k++) {
      if (dist[p[i]][k] == d[i] && black[k]) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (int j = 1; j <= N; j++) {
    cout << (black[j] ? 1 : 0);
  }
  cout << endl;
  return 0;
}
