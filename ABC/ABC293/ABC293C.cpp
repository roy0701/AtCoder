#include <iostream>
#include <set>
using namespace std;

int H, W, A[10][10];

int count(int i, int j, set<int> s) {
  if (i == H - 1 && j == W - 1) {
    return 1;
  }
  int ans = 0;
  if (i < H - 1) {
    if (s.count(A[i + 1][j]) == 0) {
      s.insert(A[i + 1][j]);
      ans += count(i + 1, j, s);
      s.erase(A[i + 1][j]);
    }
  }
  if (j < W - 1) {
    if (s.count(A[i][j + 1]) == 0) {
      s.insert(A[i][j + 1]);
      ans += count(i, j + 1, s);
      s.erase(A[i][j + 1]);
    }
  }
  return ans;
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }
  set<int> s;
  s.insert(A[0][0]);
  cout << count(0, 0, s) << endl;
  return 0;
}
