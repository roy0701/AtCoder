#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans = -1;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == 'a') ans = i + 1;
  }
  cout << ans << endl;
  return 0;
}
