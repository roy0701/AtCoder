#include <iostream>
#include <algorithm>
using namespace std;

struct CY {
  int C;
  long long Y;
};

bool operator<(const CY& cy1, const CY& cy2) noexcept {
  return cy1.C < cy2.C;
}

int main() {
  int N, M, C, Y;
  long long X[5000], dist[5001], newDist[5001];
  CY cy[5000];
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> X[i];
  for (int j = 0; j < M; j++) {
    cin >> C >> Y;
    cy[j].C = C;
    cy[j].Y = Y;
  }
  sort(cy, cy + M);
  for (int i = 0; i <= N; i++) {
    dist[i] = 0;
    newDist[i] = 0;
  }
  for (int c = 1; c <= N; c++) {
    newDist[0] = 0;
    for (int i = 0; i < c; i++) newDist[0] = max(newDist[0], dist[i]);
    int l = 0;
    for (int i = 1; i <= c; i++) {
      newDist[i] = dist[i-1] + X[c-1];
      if (cy[l].C == i) {
        newDist[i] += cy[l].Y;
        l++;
      }
    }
    for (int i = 0; i <= N; i++) dist[i] = newDist[i];
  }
  long long ans = 0;
  for (int i = 0; i <= N; i++) ans = max(ans, dist[i]);
  cout << ans << endl;
  return 0;
}
