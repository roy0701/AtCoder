#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  int N, M, dist[400*400];
  cin >> N >> M;
  vector<int> iDir = {};
  vector<int> jDir = {};
  for (int i = 0; i <= sqrt(M) + 0.5; i++) {
    int j = sqrt(M - i * i) + 0.5;
    if (i * i + j * j == M) {
      iDir.push_back(i);
      jDir.push_back(j);
    }
  }
  for (int x = 0; x < N * N; x++) dist[x] = 1000000;
  dist[0] = 0;
  vector<int> current = {0};
  vector<int> next = {};
  while (!current.empty()) {
    for (int k = 0; k < current.size(); k++) {
      int x = current[k];
      int xi = x % N;
      int xj = x / N;
      for (int c = 0; c < iDir.size(); c++) {
        int i = iDir[c];
        int j = jDir[c];
        if (xi - i >= 0) {
          if (xj - j >= 0) {
            int y = (xi - i) * N + (xj - j);
            if (dist[x] + 1 < dist[y]) {
              dist[y] = dist[x] + 1;
              next.push_back(y);
            }
          }
          if (xj + j < N) {
            int y = (xi - i) * N + (xj + j);
            if (dist[x] + 1 < dist[y]) {
              dist[y] = dist[x] + 1;
              next.push_back(y);
            }
          }
        }
        if (xi + i < N) {
          if (xj - j >= 0) {
            int y = (xi + i) * N + (xj - j);
            if (dist[x] + 1 < dist[y]) {
              dist[y] = dist[x] + 1;
              next.push_back(y);
            }
          }
          if (xj + j < N) {
            int y = (xi + i) * N + (xj + j);
            if (dist[x] + 1 < dist[y]) {
              dist[y] = dist[x] + 1;
              next.push_back(y);
            }
          }
        }
      }
    }
    current = next;
    next = {};
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int x = i * N + j;
      if (dist[x] == 1000000) cout << -1;
      else cout << dist[x];
      if (j < N - 1) cout << " ";
      else cout << endl;
    }
  }
  return 0;
}
