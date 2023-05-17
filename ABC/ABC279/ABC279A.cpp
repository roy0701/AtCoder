#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == 'v') ans++;
    else if (S[i] == 'w') ans += 2;
  }
  cout << ans << endl;
  return 0;
}
