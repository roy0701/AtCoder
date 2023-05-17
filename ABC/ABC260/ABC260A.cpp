#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S[0] == S[1]) {
    if (S[0] == S[2]) cout << -1 << endl;
    else cout << S[2] << endl;
  } else {
    if (S[0] == S[2]) cout << S[1] << endl;
    else cout << S[0] << endl;
  }
  return 0;
}
