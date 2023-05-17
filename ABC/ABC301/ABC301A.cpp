#include <iostream>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  int takahashi = 0;
  int aoki = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'T') {
      takahashi++;
    } else if (S[i] == 'A') {
      aoki++;
    }
  }
  string ans;
  if (takahashi > aoki) {
    ans = "T";
  } else if (takahashi < aoki) {
    ans = "A";
  } else {
    if (S[N - 1] == 'T') {
      ans = "A";
    } else {
      ans = "T";
    }
  }
  cout << ans << endl;
  return 0;
}
