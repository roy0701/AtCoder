#include <iostream>
using namespace std;

int main() {
  int N;
  long long A[200000];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  long long ans = 0;
  int r = 0;
  long long x = 0;
  long long sum = 0;
  for (int l = 0; l < N; l++) {
    while (r < N && (x ^ A[r]) == x + A[r]) {
      x ^= A[r];
      sum += A[r];
      r++;
    }
    ans += r - l;
    x ^= A[l];
    sum -= A[l];
  }
  cout << ans << endl;
  return 0;
}
