#include <iostream>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  bool in = false;
  bool ans = false;
  for (int i = 0; i < N; i++) {
    if (S[i] == '|') {
      in = !in;
    } else if (in && S[i] == '*') {
      ans = true;
    }
  }
  cout << (ans ? "in" : "out") << endl;
  return 0;
}
