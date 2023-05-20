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
  int N, Q, x, u, v;
  cin >> N >> Q;
  vector<vector<pair<int, int>>> edges(N + 1, vector<pair<int, int>>());
  vector<int> degrees(N + 1, 0);
  vector<int> removed(N + 1, -1);
  int ans = N;
  for (int q = 0; q < Q; q++) {
    cin >> x;
    if (x == 1) {
      cin >> u >> v;
      edges[u].push_back(make_pair(v, q));
      edges[v].push_back(make_pair(u, q));
      if (degrees[u] == 0) {
        ans--;
      }
      if (degrees[v] == 0) {
        ans--;
      }
      degrees[u]++;
      degrees[v]++;
    } else if (x == 2) {
      cin >> v;
      removed[v] = q;
      for (int i = 0; i < edges[v].size(); i++) {
        auto [u, p] = edges[v][i];
        if (p > removed[u]) {
          degrees[u]--;
          if (degrees[u] == 0) {
            ans++;
          }
        }
      }
      if (degrees[v] > 0) {
        ans++;
      }
      edges[v] = vector<pair<int, int>>();
      degrees[v] = 0;
    }
    cout << ans << endl;
  }
  return 0;
}
