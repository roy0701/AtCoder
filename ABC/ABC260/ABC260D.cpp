#include <iostream>
#include <set>
using namespace std;

int main() {
  int N, K, P, under[200000], count[200000], ans[200000];
  cin >> N >> K;
  set<int> tops;
  for (int i = 0; i < N; i++) ans[i] = -1;
  for (int i = 1; i <= N; i++) {
    cin >> P;
    P--;
    auto x = tops.upper_bound(P);
    if (x == tops.end()) {
      count[P] = 1;
      tops.insert(P);
    } else {
      under[P] = *x;
      count[P] = count[*x] + 1;
      tops.erase(*x);
      tops.insert(P);
    }
    if (count[P] == K) {
      tops.erase(P);
      for (int k = 0; k < K; k++) {
        ans[P] = i;
        P = under[P];
      }
    }
  }
  for (int i = 0; i < N; i++) cout << ans[i] << endl;
  return 0;
}
