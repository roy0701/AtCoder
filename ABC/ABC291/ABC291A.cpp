#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  for (int i = 0; i < S.length(); i++) {
    if ('A' <= S[i] && S[i] <= 'Z') {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
