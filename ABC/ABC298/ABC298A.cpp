#include <iostream>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  bool cond1 = false;
  bool cond2 = true;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'o') {
      cond1 = true;
    } else if (S[i] == 'x') {
      cond2 = false;
    }
  }
  cout << (cond1 && cond2 ? "Yes" : "No") << endl;
  return 0;
}
