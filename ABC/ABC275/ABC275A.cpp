#include <iostream>
using namespace std;

int main() {
  int N, H[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> H[i];
  int ans = 0;
  int m = H[0];
  for (int i = 1; i < N; i++) {
    if (H[i] > m) {
      ans = i;
      m = H[i];
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
