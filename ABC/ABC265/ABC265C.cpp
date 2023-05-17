#include <iostream>
using namespace std;

int main() {
  int H, W;
  string G[500];
  bool visited[500][500];
  cin >> H >> W;
  for (int i = 0; i < H; i++) cin >> G[i];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) visited[i][j] = false;
  }
  int i = 0;
  int j = 0;
  visited[i][j] = true;
  while (true) {
    if (G[i][j] == 'U' && i > 0) {
      i--;
    } else if (G[i][j] == 'D' && i < H - 1) {
      i++;
    } else if (G[i][j] == 'L' && j > 0) {
      j--;
    } else if (G[i][j] == 'R' && j < W - 1) {
      j++;
    } else {
      cout << i+1 << " " << j+1 << endl;
      return 0;
    }
    if (visited[i][j]) {
      cout << "-1" << endl;
      return 0;
    } else {
      visited[i][j] = true;
    }
  }
  return 0;
}
