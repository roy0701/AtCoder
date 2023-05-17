#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N, M, x, y;
    cin >> N >> M;
    int C[N + 1];
    for (int i = 1; i <= N; i++) {
      cin >> C[i];
    }
    vector<int> edges[N + 1];
    for (int j = 0; j < M; j++) {
      cin >> x >> y;
      edges[x].push_back(y);
      edges[y].push_back(x);
    }
    bool visited[N + 1][N + 1];
    for (int u = 1; u <= N; u++) {
      for (int v = 1; v <= N; v++) {
        visited[u][v] = false;
      }
    }
    vector<int> taka = {1};
    vector<int> aoki = {N};
    vector<int> takanext = {};
    vector<int> aokinext = {};
    visited[1][N] = true;
    for (int cnt = 1; true; cnt++) {
      for (int k = 0; k < taka.size(); k++) {
        for (int u : edges[taka[k]]) {
          for (int v : edges[aoki[k]]) {
            if (!visited[u][v] && C[u] != C[v]) {
              takanext.push_back(u);
              aokinext.push_back(v);
              visited[u][v] = true;
            }
          }
        }
      }
      taka = takanext;
      aoki = aokinext;
      takanext.clear();
      aokinext.clear();
      if (taka.empty()) {
        cout << "-1" << endl;
        break;
      } else if (visited[N][1]) {
        cout << cnt << endl;
        break;
      }
    }
  }
  return 0;
}
