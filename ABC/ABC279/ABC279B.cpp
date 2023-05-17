#include <iostream>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int m = S.length();
  int n = T.length();
  for (int i = 0; i <= m - n; i++) {
    if (S.substr(i, n) == T) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
