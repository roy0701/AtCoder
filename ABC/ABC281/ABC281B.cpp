#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  bool ans = true;
  ans &= 'A' <= S[0] && S[0] <= 'Z';
  ans &= '1' <= S[1] && S[1] <= '9';
  for (int i = 2; i <= 6; i++) ans &= '0' <= S[i] && S[i] <= '9';
  ans &= 'A' <= S[7] && S[7] <= 'Z';
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
