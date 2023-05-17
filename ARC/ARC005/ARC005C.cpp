#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char c[500][500];
int reachable[500][500];
bool flag = false;
vector<int> veci(0);
vector<int> vecj(0);
vector<int> nextveci(0);
vector<int> nextvecj(0);

void update(int i, int j, int r) {
  if (c[i][j] == 'g') {
    flag = true;
    return;
  }
  if (c[i][j] == '.' && reachable[i][j] > r) {
    reachable[i][j] = r;
    nextveci.push_back(i);
    nextvecj.push_back(j);
  } else if (c[i][j] == '#' && reachable[i][j] > r + 1 && r < 2) {
    reachable[i][j] = r + 1;
    nextveci.push_back(i);
    nextvecj.push_back(j);
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < W; j++) {
      c[i][j] = s[j];
      if (c[i][j] == 's') {
        reachable[i][j] = 0;
        veci.push_back(i);
        vecj.push_back(j);
      } else {
        reachable[i][j] = 3;
      }
    }
  }
  while (veci.size() > 0) {
    for (int k = 0; k < veci.size(); k++) {
      int i = veci.at(k);
      int j = vecj.at(k);
      int r = reachable[i][j];
      if (i > 0) update(i - 1, j, r);
      if (i < H - 1) update(i + 1, j, r);
      if (j > 0) update(i, j - 1, r);
      if (j < W - 1) update(i, j + 1, r);
      if (flag) {
        cout << "YES" << endl;
        return 0;
      }
    }
    veci = nextveci;
    vecj = nextvecj;
    nextveci.clear();
    nextvecj.clear();
  }
  cout << "NO" << endl;
  return 0;
}
