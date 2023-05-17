#include <iostream>
#include <vector>
using namespace std;

int N, X, Y, U, V;
bool visited[200001];
vector<int> edges[200001], path;

bool dfs(int v) {
  if (v == Y) return true;
  path.push_back(v);
  visited[v] = true;
  for (int k = 0; k < edges[v].size(); k++) {
    int w = edges[v][k];
    if (!visited[w]) {
      if (dfs(w)) return true;
    }
  }
  path.pop_back();
  return false;
}

int main() {
  cin >> N >> X >> Y;
  for (int i = 0; i < N; i++) {
    cin >> U >> V;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  for (int v = 1; v <= N; v++) visited[v] = false;
  dfs(X);
  for (int k = 0; k < path.size(); k++) cout << path[k] << " ";
  cout << Y << endl;
  return 0;
}
