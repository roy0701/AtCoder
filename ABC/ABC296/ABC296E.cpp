#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, A[200001];
  bool cycle[200001], visited[200001];
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= N; i++) {
    visited[i] = false;
  }
  for (int i = 1; i <= N; i++) {
    vector<int> path;
    int x = i;
    while (!visited[x]) {
      visited[x] = true;
      path.push_back(x);
      x = A[x];
    }
    bool flag = false;
    for (int j = 0; j < path.size(); j++) {
      if (path[j] == x) {
        flag = true;
      }
      cycle[path[j]] = flag;
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (cycle[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
