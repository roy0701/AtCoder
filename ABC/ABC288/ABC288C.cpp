#include <iostream>
#include <vector>
using namespace std;

int parent[200001];

int root(int x) {
  if (parent[x] == x)
    return x;
  else
    return parent[x] = root(parent[x]);
}

int same(int x, int y) {
  int rx = root(x);
  int ry = root(y);
  return rx == ry;
}

void unite(int x, int y) {
  int rx = root(x);
  int ry = root(y);
  if (!same(rx, ry)) parent[rx] = ry;
}

int main() {
  int N, M, A, B, size[200001];
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    parent[i] = i;
    size[i] = 0;
  }
  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    unite(A, B);
  }
  for (int i = 1; i <= N; i++) size[root(i)]++;
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    if (size[i] > 0) sum += size[i] - 1;
  }
  cout << M - sum << endl;
  return 0;
}
