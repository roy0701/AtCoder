#include <iostream>
using namespace std;

string S, T;

bool match(int i, int j) {
  return S[i] == T[j] || S[i] == '?' || T[j] == '?';
}

int main() {
  cin >> S >> T;
  int n = S.length();
  int m = T.length();
  int i = 0;
  while (i < m) {
    if (!match(i, i)) break;
    i++;
  }
  int j = 0;
  while (j < m) {
    if (!match(n - 1 - j, m - 1 - j)) break;
    j++;
  }
  for (int x = 0; x <= m; x++) {
    if (x <= i && m - x <= j) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
