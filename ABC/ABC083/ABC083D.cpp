#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n = S.length();
  int ans = n;
  for (int k = 0; k < n - 1; k++) {
    if (S[k] != S[k+1]) ans = min(ans, max(k + 1, n - k - 1));
  }
  cout << ans << endl;
  return 0;
}
