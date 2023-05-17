#include <iostream>
using namespace std;

int main() {
  int N, M, U, V, ans;
  bool edges[100][100];
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) edges[i][j] = false;
  }
  for (int k = 0; k < M; k++) {
    cin >> U >> V;
    edges[U-1][V-1] = true;
    edges[V-1][U-1] = true;
  }
  ans = 0;
  for (int a = 0; a < N-2; a++) {
    for (int b = a+1; b < N-1; b++) {
      if (edges[a][b]) {
        for (int c = b+1; c < N; c++) {
          if (edges[b][c] && edges[c][a]) ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
