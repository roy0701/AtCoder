#include <iostream>
using namespace std;

int main() {
  int H, W, N, h, w, n, A[301][301], num[301], count[301];
  cin >> H >> W >> N >> h >> w;
  for (n = 1; n <= N; n++) num[n] = 0;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> n;
      A[i][j] = n;
      num[n]++;
    }
  }
  for (int k = 0; k <= H - h; k++) {
    for (int l = 0; l <= W - w; l++) {
      for (int m = 1; m <= N; m++) count[m] = 0;
      for (int i = k+1; i <= k + h; i++) {
        for (int j = l+1; j <= l + w; j++) count[A[i][j]]++;
      }
      int ans = 0;
      for (int m = 1; m <= N; m++) {
        if (num[m] > count[m]) ans++;
      }
      cout << ans;
      if (l < W - w) cout << " ";
      else cout << endl;
    }
  }
  return 0;
}
