#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> a(M, vector<int>(N, 0));
  vector<vector<bool>> bad(N + 1, vector<bool>(N + 1, true));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N - 1; j++) {
      bad[a[i][j]][a[i][j + 1]] = false;
      bad[a[i][j + 1]][a[i][j]] = false;
    }
  }
  int ans = 0;
  for (int k = 1; k <= N; k++) {
    for (int l = k + 1; l <= N; l++) {
      if (bad[k][l]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
