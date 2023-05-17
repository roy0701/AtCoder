#include <iostream>
using namespace std;

int R, r[8], dist[200][200];

int findMin(int d, int now, int visited) {
  if (visited == (1 << R) - 1) return d;
  int ans = 1e9;
  int v = visited;
  for (int j = 0; j < R; j++) {
    if (v % 2 == 0) ans = min(ans, findMin(d + dist[r[now]][r[j]], j, visited | (1 << j)));
    v >>= 1;
  }
  return ans;
}

int main() {
  int N, M, A, B, C;
  cin >> N >> M >> R;
  for (int j = 0; j < R; j++) {
    cin >> r[j];
    r[j]--;
  }
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) dist[u][v] = u == v ? 0 : 1e9;
  }
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    dist[A-1][B-1] = C;
    dist[B-1][A-1] = C;
  }
  for (int w = 0; w < N; w++) {
    for (int u = 0; u < N; u++) {
      for (int v = 0; v < N; v++) dist[u][v] = min(dist[u][v], dist[u][w] + dist[w][v]);
    }
  }
  int ans = 1e9;
  for (int j = 0; j < R; j++) ans = min(ans, findMin(0, j, 1 << j));
  cout << ans << endl;
  return 0;
}
