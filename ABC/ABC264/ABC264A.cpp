#include <iostream>
using namespace std;

int main() {
  string s = "atcoder";
  int L, R;
  cin >> L >> R;
  for (int i = L - 1; i <= R - 1; i++) {
    cout << s[i];
  }
  cout << endl;
  return 0;
}
