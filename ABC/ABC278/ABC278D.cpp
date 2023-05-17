#include <iostream>
#include <deque>
using namespace std;

int main() {
  int N, Q, k, i, x;
  long long A[200000];
  deque<int> ihist, xhist;
  cin >> N;
  for (i = 0; i < N; i++) cin >> A[i];
  cin >> Q;
  int common = -1;
  int cnt = 0;
  for (int q = 0; q < Q; q++) {
    cin >> k;
    if (k == 1) {
      cin >> x;
      common = x;
      cnt = 0;
    } else if (k == 2) {
      cin >> i >> x;
      i--;
      if (common < 0) A[i] += x;
      else {
        ihist.push_front(i);
        xhist.push_front(x);
      }
      cnt++;
    } else {
      cin >> i;
      i--;
      long long ans = common;
      if (common < 0) ans = A[i];
      else {
        for (int l = 0; l < cnt; l++) {
          int j = ihist[l];
          if (j == i) ans += xhist[l];
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
