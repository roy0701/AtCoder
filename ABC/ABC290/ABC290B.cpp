#include <iostream>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> K;
  cin >> S;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'o') {
      if (cnt < K) {
        cnt++;
      } else {
        S[i] = 'x';
      }
    }
  }
  cout << S << endl;
  return 0;
}
