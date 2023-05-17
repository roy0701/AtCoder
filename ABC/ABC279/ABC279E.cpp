#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  int N, M, A[200001], ans[200001];
  vector<set<int>> s(200001);
  cin >> N >> M;
  for (int i = 1; i <= M; i++) cin >> A[i];
  for (int j = 1; j <= M; j++) s[1].insert(j);
  for (int k = 1; k <= M; k++) {
    s[A[k]].swap(s[A[k]+1]);
    if (s[A[k]].count(k)) {
      s[A[k]].erase(k);
      s[A[k]+1].insert(k);
    } else if (s[A[k]+1].count(k)) {
      s[A[k]].insert(k);
      s[A[k]+1].erase(k);
    }
  }
  for (int j = 1; j <= N; j++) {
    for (int i : s[j]) ans[i] = j;
  }
  for (int i = 1; i <= M; i++) cout << ans[i] << endl;
  return 0;
}
