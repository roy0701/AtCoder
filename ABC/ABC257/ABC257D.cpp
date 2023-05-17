#include <iostream>
#include <queue>
using namespace std;

int N;
long long x[200], y[200], P[200];

long long binarySearch(long long l, long long r) {
  if (l == r) return l;
  vector<int> edges[200];
  bool visited[200];
  long long m = (l + r) / 2;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (P[i] * m >= abs(x[i] - x[j]) + abs(y[i] - y[j])) edges[i].push_back(j);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) visited[j] = false;
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int k = 0; k < edges[v].size(); k++) {
        int w = edges[v][k];
        if (!visited[w]) {
          q.push(w);
          visited[w] = true;
        }
      }
    }
    bool flag = true;
    for (int j = 0; j < N; j++) {
      if (!visited[j]) {
        flag = false;
        break;
      }
    }
    if (flag) return binarySearch(l, m);
  }
  return binarySearch(m + 1, r);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> x[i] >> y[i] >> P[i];
  cout << binarySearch(0, 4000000000) << endl;
  return 0;
}
