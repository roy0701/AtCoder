#include <iostream>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] != T[i]) {
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << S.length()+1 << endl;
  return 0;
}
