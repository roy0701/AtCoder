#include <iostream>
using namespace std;

int main() {
  int N;
  string A[1000];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      if (A[i][j] == 'W' && A[j][i] == 'L') continue;
      if (A[i][j] == 'L' && A[j][i] == 'W') continue;
      if (A[i][j] == 'D' && A[j][i] == 'D') continue;
      cout << "incorrect" << endl;
      return 0;
    }
  }
  cout << "correct" << endl;
  return 0;
}
