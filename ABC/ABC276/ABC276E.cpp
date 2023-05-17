#include <iostream>
#include <vector>
using namespace std;

int H, W, x, y;
char C[1000000];
bool visited[1000000];

void bfs(vector<int> vec) {
  int k = 0;
  while (k < vec.size()) {
    int n = vec[k];
    int i = n / W;
    int j = n % W;
    if (i > 0 && !visited[n - W] && C[n - W] == '.') {
      visited[n - W] = true;
      vec.push_back(n - W);
    }
    if (i < H - 1 && !visited[n + W] && C[n + W] == '.') {
      visited[n + W] = true;
      vec.push_back(n + W);
    }
    if (j > 0 && !visited[n - 1] && C[n - 1] == '.') {
      visited[n - 1] = true;
      vec.push_back(n - 1);
    }
    if (j < W - 1 && !visited[n + 1] && C[n + 1] == '.') {
      visited[n + 1] = true;
      vec.push_back(n + 1);
    }
    k++;
  }
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> C[i * W + j];
      if (C[i * W + j] == 'S') {
        x = i;
        y = j;
      }
    }
  }
  bool ans = false;
  if (x > 0 && C[(x-1) * W + y] == '.') {
    for (int k = 0; k < H * W; k++) visited[k] = false;
    bfs({(x-1) * W + y});
    if (x < H - 1 && visited[(x+1) * W + y]) ans = true;
    if (y > 0 && visited[x * W + (y-1)]) ans = true;
    if (y < W - 1 && visited[x * W + (y+1)]) ans = true;
  }
  if (!ans && x < H - 1 && C[(x+1) * W + y] == '.') {
    for (int k = 0; k < H * W; k++) visited[k] = false;
    bfs({(x+1) * W + y});
    if (y > 0 && visited[x * W + (y-1)]) ans = true;
    if (y < W - 1 && visited[x * W + (y+1)]) ans = true;
  }
  if (!ans && y > 0 && C[x * W + (y-1)] == '.') {
    for (int k = 0; k < H * W; k++) visited[k] = false;
    bfs({x * W + (y-1)});
    if (y < W - 1 && visited[x * W + (y+1)]) ans = true;
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
