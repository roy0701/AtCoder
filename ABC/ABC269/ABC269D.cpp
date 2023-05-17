#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int N, X[1000], Y[1000];
  bool visited[1000];
  vector<int> edges[1000];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
  for (int i = 0; i < N; i++) {
    visited[i] = false;
    for (int j = i + 1; j < N; j++) {
      bool connected = false;
      if (X[i] == X[j] - 1) connected = Y[i] == Y[j] - 1 || Y[i] == Y[j];
      else if (X[i] == X[j]) connected = Y[i] == Y[j] - 1 || Y[i] == Y[j] + 1;
      else if (X[i] == X[j] + 1) connected = Y[i] == Y[j] || Y[i] == Y[j] + 1;
      if (connected) {
        edges[i].push_back(j);
        edges[j].push_back(i);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      ans++;
      queue<int> q;
      q.push(i);
      visited[i] = true;
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int j = 0; j < edges[v].size(); j++) {
          int w = edges[v][j];
          if (!visited[w]) {
            q.push(w);
            visited[w] = true;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
