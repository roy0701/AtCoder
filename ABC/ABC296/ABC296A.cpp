#include <iostream>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  char first = S[0];
  for (int i = 1; i < N; i++) {
    bool ok;
    if (i % 2 == 0) {
      ok = S[i] == first;
    } else {
      ok = S[i] != first;
    }
    if (!ok) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
