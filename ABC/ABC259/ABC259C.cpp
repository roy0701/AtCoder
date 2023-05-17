#include <iostream>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int i = 0;
  int j = 0;
  while (i < S.length() && j < T.length()) {
    if (S[i] == T[j]) {
      char c = S[i];
      i++;
      j++;
      if (i < S.length() && j < T.length() && S[i] == c && T[j] == c) {
        i++;
        j++;
        while (i < S.length() && j < T.length() && S[i] == c && T[j] == c) {
          i++;
          j++;
        }
        while (j < T.length() && T[j] == c) j++;
      }
    } else {
      break;
    }
  }
  if (i == S.length() && j == T.length()) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
