#include <iostream>
using namespace std;

bool valid1(char c) {
  return c == 'H' || c == 'D' || c == 'C' || c == 'S';
}

bool valid2(char c) {
  return c == 'A' || c == 'T' || c == 'J' || c == 'Q' || c == 'K' || (c - '0' >= 2 && c - '0' <= 9);
}

bool valid(string s) {
  return valid1(s[0]) && valid2(s[1]);
}

int main() {
  int N;
  string S[52];
  cin >> N;
  bool ans = true;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    ans &= valid(S[i]);
    for (int j = 0; j < i; j++) {
      if (S[i] == S[j]) {
        ans = false;
        break;
      }
    }
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
