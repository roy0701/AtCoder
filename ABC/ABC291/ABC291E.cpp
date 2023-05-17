#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M, X, Y, indexes[200000], ans[200000];
  bool visited[200001];
  map<int, vector<int>> smaller, larger;
  set<pair<int, int>> s;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> X >> Y;
    if (s.count(make_pair(X, Y)) == 0) {
      smaller[X].push_back(Y);
      larger[Y].push_back(X);
      s.insert(make_pair(X, Y));
    }
  }
  int smallest = 0;
  for (int x = 1; x <= N; x++) {
    visited[x] = false;
    if (larger[x].size() == 0) {
      if (smallest == 0) {
        smallest = x;
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  indexes[0] = smallest;
  visited[smallest] = true;
  for (int i = 1; i < N; i++) {
    int next = 0;
    for (int x : smaller[indexes[i - 1]]) {
      bool ok = true;
      for (int y : larger[x]) {
        if (!visited[y]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        if (next == 0) {
          next = x;
        } else {
          cout << "No" << endl;
          return 0;
        }
      }
    }
    indexes[i] = next;
    visited[next] = true;
  }
  for (int i = 0; i < N; i++) {
    ans[indexes[i] - 1] = i + 1;
  }
  cout << "Yes" << endl;
  for (int i = 0; i < N - 1; i++) {
    cout << ans[i] << " ";
  }
  cout << ans[N - 1] << endl;
  return 0;
}
