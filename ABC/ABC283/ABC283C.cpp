#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans = S.length();
  bool prev0 = false;
  for (int i = 0; i < S.length(); i++) {
    if (prev0 && S[i] == '0') {
      ans--;
      prev0 = false;
    } else {
      prev0 = S[i] == '0';
    }
  }
  cout << ans << endl;
  return 0;
}
