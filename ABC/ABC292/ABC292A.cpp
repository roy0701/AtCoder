#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  for (int i = 0; i < S.length(); i++) {
    S[i] = S[i] + 'A' - 'a';
  }
  cout << S << endl;
  return 0;
}
