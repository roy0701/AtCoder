#include <iostream>
using namespace std;

int main() {
  int N;
  int t[100001], x[100001], y[100001];
  cin >> N;
  t[0] = 0;
  x[0] = 0;
  y[0] = 0;
  for (int i = 1; i <= N; i++) cin >> t[i] >> x[i] >> y[i];
  int i;
  for (i = 1; i <= N; i++) {
    if (abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]) > t[i] - t[i-1]) break;
    if (t[i] % 2 != abs(x[i] + y[i]) % 2) break;
  }
  if (i > N) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
