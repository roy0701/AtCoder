#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, M, a, b;
  vector<int> adj[100001];
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int k = 1; k <= N; k++) {
    sort(adj[k].begin(), adj[k].end());
    int size = adj[k].size();
    cout << size;
    for (int j = 0; j < size; j++) cout << " " << adj[k][j];
    cout << endl;
  }
  return 0;
}
