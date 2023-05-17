#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    cout << (s[i] == '0' ? '1' : '0');
  }
  cout << endl;
  return 0;
}
