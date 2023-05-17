#include <iostream>
using namespace std;

int main() {
  int N;
  string S[99];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> S[i];
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == "For") cnt++;
  }
  if (cnt > N / 2) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
