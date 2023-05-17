#include <iostream>
using namespace std;

int N;
bool edges[8][8];

int count(int a, int unvisited) {
  if (unvisited == 0) return 1;
  int ans = 0;
  for (int b = 1; b < N; b++) {
    if (edges[a][b] && (unvisited & 1 << b) > 0) ans += count(b, unvisited - (1 << b));
  }
  return ans;
}

int main() {
  int M, a, b;
  cin >> N >> M;
  for (a = 0; a < N; a++) {
    for (b = 0; b < N; b++) edges[a][b] = false;
  }
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    edges[a-1][b-1] = true;
    edges[b-1][a-1] = true;
  }
  cout << count(0, (1 << N) - 2) << endl;
  return 0;
}
