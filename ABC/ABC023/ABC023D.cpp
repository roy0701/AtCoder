#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long H[100000], S[100000];

bool isPossible(long long bound) {
  long long limit[100000];
  for (int i = 0; i < N; i++) {
    if (bound < H[i]) return false;
    limit[i] = (bound - H[i]) / S[i];
  }
  sort(limit, limit + N);
  for (int i = 0; i < N; i++) {
    if (limit[i] < i) return false;
  }
  return true;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> H[i] >> S[i];
  long long l = 0;
  long long r = 1e18;
  while (l + 1 < r) {
    long long m = (l + r) / 2;
    if (isPossible(m)) r = m;
    else l = m;
  }
  cout << r << endl;
  return 0;
}
