#include <iostream>
using namespace std;

long long sum[200001];

int binarySearch(long long x, int l, int r) {
  if (l > r) return -1;
  int m = (l + r) / 2;
  if (x < sum[m]) return binarySearch(x, l, m - 1);
  else if (x > sum[m]) return binarySearch(x, m + 1, r);
  else return m;
}

int main() {
  int N;
  long long P, Q, R, A[200000];
  cin >> N >> P >> Q >> R;
  for (int i = 0; i < N; i++) cin >> A[i];
  sum[0] = 0;
  for (int i = 1; i <= N; i++) sum[i] = sum[i-1] + A[i-1];
  int x = 0;
  int y = 1;
  while (y <= N) {
    long long s = sum[y] - sum[x];
    if (s < P) {
      y++;
    } else if (s > P) {
      x++;
    } else {
      int z = binarySearch(sum[y] + Q, y + 1, N);
      if (z >= 0) {
        int w = binarySearch(sum[z] + R, z + 1, N);
        if (w >= 0) {
          cout << "Yes" << endl;
          return 0;
        }
      }
      x++;
      y++;
    }
  }
  cout << "No" << endl;
  return 0;
}
