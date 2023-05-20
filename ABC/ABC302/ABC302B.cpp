#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int dirX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dirY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const string snuke = "snuke";

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H, "");
  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == 's') {
        for (int k = 0; k < 8; k++) {
          bool ok = true;
          int x = i + dirX[k];
          int y = j + dirY[k];
          for (int l = 1; l < 5; l++) {
            if (0 <= x && x < H && 0 <= y && y < W) {
              if (S[x][y] == snuke[l]) {
                x += dirX[k];
                y += dirY[k];
                continue;
              }
            }
            ok = false;
            break;
          }
          if (ok) {
            x = i + 1;
            y = j + 1;
            for (int l = 0; l < 5; l++) {
              cout << x << " " << y << endl;
              x += dirX[k];
              y += dirY[k];
            }
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
