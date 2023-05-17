#include <iostream>
#include <algorithm>
using namespace std;

long long a[30000], b[30000];

int binarySearch(long long bound, int i, int l, int r) {
  if (l + 1 == r) return r;
  int m = (l + r) / 2;
  if (a[i] * b[m] > bound) return binarySearch(bound, i, l, m);
  else return binarySearch(bound, i, m, r);
}

int main() {
  int N;
  long long K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) cin >> b[i];
  sort(b, b + N);
  long long l = 0;
  long long r = 1e9 * 1e9 + 1;
  while (l + 1 < r) {
    long long m = (l + r) / 2;
    int sum = 0;
    for (int i = 0; i < N; i++) sum += binarySearch(m, i, -1, N);
    if (sum >= K) r = m;
    else l = m;
  }
  cout << r << endl;
  return 0;
}
