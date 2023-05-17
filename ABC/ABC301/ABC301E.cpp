#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1000000000

int H, W;
char A[300][300];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

vector<vector<int>> dist(int si, int sj) {
  vector res(H, vector<int>(W, INF));
  res[si][sj] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(si, sj));
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (0 <= x && x < H && 0 <= y && y < W && A[x][y] != '#') {
        if (res[x][y] > res[i][j] + 1) {
          res[x][y] = res[i][j] + 1;
          q.push(make_pair(x, y));
        }
      }
    }
  }
  return res;
}

int main() {
  int T, si, sj, gi, gj, oi[18], oj[18];
  cin >> H >> W >> T;
  int n = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
      if (A[i][j] == 'S') {
        si = i;
        sj = j;
      } else if (A[i][j] == 'G') {
        gi = i;
        gj = j;
      } else if (A[i][j] == 'o') {
        oi[n] = i;
        oj[n] = j;
        n++;
      }
    }
  }
  vector d(n, vector<vector<int>>());
  for (int k = 0; k < n; k++) {
    d[k] = dist(oi[k], oj[k]);
  }
  vector dp(1 << n, vector<int>(n, INF));
  for (int k = 0; k < n; k++) {
    dp[1 << k][k] = d[k][si][sj];
  }
  for (int s = 1; s < (1 << n); s++) {
    for (int k = 0; k < n; k++) {
      if (dp[s][k] < INF) {
        for (int l = 0; l < n; l++) {
          dp[s | (1 << l)][l] =
              min(dp[s | (1 << l)][l], dp[s][k] + d[k][oi[l]][oj[l]]);
        }
      }
    }
  }
  int ans = -1;
  if (dist(si, sj)[gi][gj] <= T) {
    ans = 0;
  }
  for (int s = 1; s < (1 << n); s++) {
    for (int k = 0; k < n; k++) {
      if (dp[s][k] + d[k][gi][gj] <= T) {
        int x = 0;
        for (int l = 0; l < n; l++) {
          if (s & (1 << l)) {
            x++;
          }
        }
        ans = max(ans, x);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
