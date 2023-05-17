#include <iostream>
using namespace std;

int main() {
  int N, M, A, C, edges[400001][2];
  char B, D;
  bool visited[400001];
  cin >> N >> M;
  for (int j = 1; j <= N; j++) {
    edges[j][0] = j + N;
    edges[j + N][0] = j;
    edges[j][1] = 0;
    edges[j + N][1] = 0;
    visited[j] = false;
    visited[j + N] = false;
  }
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C >> D;
    if (B == 'B') {
      A += N;
    }
    if (D == 'B') {
      C += N;
    }
    edges[A][1] = C;
    edges[C][1] = A;
  }
  int loop = 0;
  int nonloop = 0;
  for (int j = 1; j <= N * 2; j++) {
    if (!visited[j]) {
      visited[j] = true;
      int prev = j;
      int now = edges[j][0];
      bool flag = false;
      while (true) {
        visited[now] = true;
        int next = edges[now][0];
        if (next == prev) {
          if (edges[now][1] == 0) {
            nonloop++;
            flag = true;
            break;
          } else {
            next = edges[now][1];
          }
        }
        if (next == j) {
          loop++;
          break;
        }
        prev = now;
        now = next;
      }
      if (flag) {
        prev = j;
        now = edges[j][1];
        while (now != 0) {
          visited[now] = true;
          int next = edges[now][0];
          if (next == prev) {
            next = edges[now][1];
          }
          prev = now;
          now = next;
        }
      }
    }
  }
  cout << loop << " " << nonloop << endl;
  return 0;
}
