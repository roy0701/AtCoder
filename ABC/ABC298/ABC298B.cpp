#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, a, B[101][101];
  vector<int> row, col;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a;
      if (a) {
        row.push_back(i);
        col.push_back(j);
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> B[i][j];
    }
  }
  for (int r = 0; r < 4; r++) {
    bool ok = true;
    for (int k = 0; k < row.size(); k++) {
      int i = row[k];
      int j = col[k];
      if (r == 0) {
        ok &= B[i][j];
      } else if (r == 1) {
        ok &= B[N + 1 - j][i];
      } else if (r == 2) {
        ok &= B[N + 1 - i][N + 1 - j];
      } else if (r == 3) {
        ok &= B[j][N + 1 - i];
      }
    }
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
