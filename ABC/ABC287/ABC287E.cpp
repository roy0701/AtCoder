#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int lcp(string x, string y) {
  int i;
  for (i = 0; i < min(x.length(), y.length()); i++) {
    if (x[i] != y[i]) return i;
  }
  return i;
}

int main() {
  int N, res[500000], ans[500000];
  string S;
  vector<pair<string,int>> p;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S;
    p.push_back(make_pair(S, i));
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < N - 1; i++) res[i] = lcp(p[i].first, p[i + 1].first);
  ans[p[0].second] = res[0];
  for (int i = 1; i < N - 1; i++) ans[p[i].second] = max(res[i-1], res[i]);
  ans[p[N-1].second] = res[N-2];
  for (int i = 0; i < N; i++) cout << ans[i] << endl;
  return 0;
}
