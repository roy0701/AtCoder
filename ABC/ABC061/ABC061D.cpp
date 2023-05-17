#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
  int N, M, a[2000], b[2000];
  long long c[2000], score[1000];
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }
  score[0] = 0;
  for (int v = 1; v < N; v++) score[v] = -1e13;
  for (int v = 1; v < N; v++) {
    for (int i = 0; i < M; i++) score[b[i]] = max(score[b[i]], score[a[i]] + c[i]);
  }
  long long ans = score[N-1];
  for (int v = 0; v < N; v++) {
    for (int i = 0; i < M; i++) score[b[i]] = max(score[b[i]], score[a[i]] + c[i]);
    if (score[N-1] > ans) {
      cout << "inf" << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}
