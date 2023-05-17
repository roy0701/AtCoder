#include <iostream>
using namespace std;

int main() {
  int H, W;
  string s[52];
  cin >> H >> W;
  s[0] = string(W, '.');
  for (int i = 1; i <= H; i++) {
    cin >> s[i];
    s[i] = "." + s[i] + ".";
  }
  s[H + 1] = string(W, '.');
  bool flag = true;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (s[i][j] == '#') {
        if (s[i - 1][j] == '.' && s[i][j - 1] == '.' && s[i][j + 1] == '.' && s[i + 1][j] == '.') {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
