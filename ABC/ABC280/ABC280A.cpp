#include <iostream>
using namespace std;

int main() {
  int H, W;
  char S[10][10];
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> S[i][j];
  }
  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
