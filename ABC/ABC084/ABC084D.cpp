#include <iostream>
using namespace std;

int main() {
  int Q, l, r, count[50000];
  bool isPrime[100001];
  isPrime[0] = false;
  isPrime[1] = false;
  for (int x = 2; x <= 100000; x++) isPrime[x] = true;
  for (int x = 2; x * x <= 100000; x++) {
    for (int y = 2 * x; y <= 100000; y += x) isPrime[y] = false;
  }
  count[0] = 0;
  for (int n = 1; n < 50000; n++) {
    count[n] = count[n-1];
    if (isPrime[2*n+1] && isPrime[n+1]) count[n]++;
  }
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> l >> r;
    if (l == 1) cout << count[r/2] << endl;
    else cout << count[r/2] - count[l/2-1] << endl;
  }
  return 0;
}
