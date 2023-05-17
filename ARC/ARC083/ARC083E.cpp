#include <iostream>
using namespace std;

int dp[1001][5001];

int main() {
  int N, P[1000], X[1000], Y[1000], children[1000];
  cin >> N;
  P[0] = -1;
  for (int i = 1; i < N; i++) {
    cin >> P[i];
    P[i]--;
  }
  for (int i = 0; i < N; i++) cin >> X[i];
  for (int i = N - 1; i >= 0; i--) {
    int numberChildren = 0;
    for (int j = i + 1; j < N; j++) {
      if (P[j] == i) {
        children[numberChildren] = j;
        numberChildren++;
      }
    }
    if (numberChildren == 0) {
      Y[i] = 0;
    } else {
      int sum = 0;
      for (int k = 0; k < numberChildren; k++) sum += min(X[children[k]], Y[children[k]]);
      if (sum > X[i]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
      for (int x = 0; x <= X[i]; x++) dp[0][x] = 0;
      for (int k = 1; k <= numberChildren; k++) {
        for (int x = 0; x <= X[i]; x++) {
          dp[k][x] = 2e9;
          if (x >= X[children[k-1]]) dp[k][x] = min(dp[k][x], dp[k-1][x-X[children[k-1]]] + Y[children[k-1]]);
          if (x >= Y[children[k-1]]) dp[k][x] = min(dp[k][x], dp[k-1][x-Y[children[k-1]]] + X[children[k-1]]);
        }
      }
      Y[i] = dp[numberChildren][X[i]];
    }
  }
  cout << "POSSIBLE" << endl;
  return 0;
}
