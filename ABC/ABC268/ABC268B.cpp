#include <iostream>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] != T[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
