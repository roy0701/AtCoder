#include <iostream>
#include <set>
using namespace std;

bool pawn[9][9];

bool valid(int r, int c) {
  if (0 <= r && r < 9 && 0 <= c && c < 9) return pawn[r][c];
  else return false;
}

int main() {
  string S;
  for (int r = 0; r < 9; r++) {
    cin >> S;
    for (int c = 0; c < 9; c++) pawn[r][c] = S[c] == '#';
  }
  set<set<pair<int,int>>> squares;
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      for (int x = -8; x <= 8; x++) {
        for (int y = -8; y <= 8; y++) {
          if (x == 0 && y == 0) continue;
          int r2 = r + x;
          int c2 = c + y;
          int r3 = r2 - y;
          int c3 = c2 + x;
          int r4 = r3 - x;
          int c4 = c3 - y;
          if (valid(r, c) && valid(r2, c2) && valid(r3, c3) && valid(r4, c4)) {
            set<pair<int,int>> points;
            points.insert(make_pair(r, c));
            points.insert(make_pair(r2, c2));
            points.insert(make_pair(r3, c3));
            points.insert(make_pair(r4, c4));
            squares.insert(points);
          }
        }
      }
    }
  }
  cout << squares.size() << endl;
  return 0;
}
