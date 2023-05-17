#include <iostream>
using namespace std;

int main() {
  int H, W;
  char C[1000][1000];
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> C[i][j];
  }
  for (int j = 0; j < W; j++) {
    int x = 0;
    for (int i = 0; i < H; i++) {
      if (C[i][j] == '#') x++;
    }
    if (j < W - 1) cout << x << " ";
    else cout << x << endl;
  }
  return 0;
}
