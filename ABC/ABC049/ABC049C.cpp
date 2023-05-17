#include <iostream>
using namespace std;

string keywords[] = {"dream", "dreamer", "erase", "eraser"};

int main() {
  string S;
  cin >> S;
  int i = S.size();
  while (i > 0) {
    bool flag = true;
    for (int j = 0; j < 4; j++) {
      string k = keywords[j];
      int l = k.size();
      if (i >= l && S.substr(i - l, l) == k) {
        i -= l;
        flag = false;
        break;
      }
    }
    if (flag) break;
  }
  if (i == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
