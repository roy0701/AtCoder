#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M, H, K, x, y;
  string S;
  cin >> N >> M >> H >> K;
  cin >> S;
  map<int, set<int>> items;
  for (int i = 0; i < M; i++) {
    cin >> x >> y;
    items[x].insert(y);
  }
  x = 0;
  y = 0;
  for (int t = 0; t < N; t++) {
    H--;
    if (S[t] == 'R') {
      x++;
    } else if (S[t] == 'L') {
      x--;
    } else if (S[t] == 'U') {
      y++;
    } else if (S[t] == 'D') {
      y--;
    }
    if (H < 0) {
      cout << "No" << endl;
      return 0;
    } else if (H < K && items[x].count(y) == 1) {
      items[x].erase(y);
      H = K;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
