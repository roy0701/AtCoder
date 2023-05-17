#include <iostream>
using namespace std;

int main() {
  int N, k, a[500000];
  long long ans;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  k = 0;
  ans = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] == i+1) {
      ans += k;
      k++;
    } else if (a[i] > i+1) {
      int j = a[i] - 1;
      if (a[j] == i+1) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
