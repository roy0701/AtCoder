#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
  int T, N, A;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
      cin >> A;
      if (A % 2 == 1) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
