#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#define INF 1000000000

int main() {
  int N, M, A, S;
  cin >> N >> M;
  vector<vector<int>> edges(N + M + 1, vector<int>());
  for (int i = 0; i < N; i++) {
    cin >> A;
    for (int j = 0; j < A; j++) {
      cin >> S;
      edges[i].push_back(N + S);
      edges[N + S].push_back(i);
    }
  }
  vector<int> dist(N + M + 1, INF);
  queue<int> q;
  q.push(N + 1);
  dist[N + 1] = -1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : edges[v]) {
      if (dist[u] == INF) {
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
  }
  cout << (dist[N + M] == INF ? -1 : dist[N + M] / 2) << endl;
  return 0;
}
