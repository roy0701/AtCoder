#include <iostream>
#include <set>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  set<pair<int, int>> pos;
  int x = 0;
  int y = 0;
  pos.insert(make_pair(x, y));
  bool ans = false;
  for (int i = 0; i < N; i++) {
    char d = S[i];
    if (d == 'R') {
      x++;
    } else if (d == 'L') {
      x--;
    } else if (d == 'U') {
      y++;
    } else if (d == 'D') {
      y--;
    }
    if (pos.count(make_pair(x, y))) {
      ans = true;
      break;
    }
    pos.insert(make_pair(x, y));
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
