#include <iostream>
using namespace std;

int main() {
  int N, P[51];
  cin >> N;
  for (int i = 2; i <= N; i++) cin >> P[i];
  int k = N;
  int ans = 0;
  while (k > 1) {
    k = P[k];
    ans++;
  }
  cout << ans << endl;
  return 0;
}
