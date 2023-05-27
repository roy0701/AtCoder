#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  string S, T;
  cin >> N;
  cin >> S >> T;
  bool ans = true;
  for (int i = 0; i < N; i++) {
    if (S[i] == T[i]) {
      continue;
    } else if ((S[i] == '1' && T[i] == 'l') || S[i] == 'l' && T[i] == '1') {
      continue;
    } else if ((S[i] == '0' && T[i] == 'o') || S[i] == 'o' && T[i] == '0') {
      continue;
    } else {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
