#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, a[300000], ans;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N);
  int i = 0;
  int rem = N;
  for (ans = 0; rem > 0; ans++) {
    while (a[i] < ans + 1) i++;
    if (a[i] == ans + 1) {
      i++;
      rem--;
    } else if (rem >= 2) {
      rem -= 2;
    }
    else break;
  }
  cout << ans << endl;
  return 0;
}
