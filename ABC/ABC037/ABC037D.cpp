#include <iostream>
using namespace std;

const int mod = 1e9 + 7;
int H, W, a[1000][1000], dp[1000][1000];

int dfs(int i, int j) {
  if (dp[i][j] > 0) return dp[i][j];
  int count = 1;
  if (i > 0 && a[i-1][j] > a[i][j]) count = (count + dfs(i-1, j)) % mod;
  if (j > 0 && a[i][j-1] > a[i][j]) count = (count + dfs(i, j-1)) % mod;
  if (i < H - 1 && a[i+1][j] > a[i][j]) count = (count + dfs(i+1, j)) % mod;
  if (j < W - 1 && a[i][j+1] > a[i][j]) count = (count + dfs(i, j+1)) % mod;
  dp[i][j] = count;
  return count;
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
      dp[i][j] = 0;
    }
  }
  int sum = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) sum = (sum + dfs(i, j)) % mod;
  }
  cout << sum << endl;
  return 0;
}
