#include <iostream>
using namespace std;

int main() {
  int depth[26];
  bool box[26];
  string S;
  cin >> S;
  for (int c = 0; c < 26; c++) box[c] = false;
  int d = 0;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == '(') {
      d++;
    } else if (S[i] == ')') {
      for (int c = 0; c < 26; c++) {
        if (depth[c] == d) box[c] = false;
      }
      d--;
    } else {
      int c = S[i] - 'a';
      if (box[c]) {
        cout << "No" << endl;
        return 0;
      }
      depth[c] = d;
      box[c] = true;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
