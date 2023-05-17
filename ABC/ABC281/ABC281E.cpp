#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int binsearch1(int x, int l, int r) {
  int m = (l + r) / 2;
  if (x == v[m]) return m;
  else if (x < v[m]) return binsearch1(x, l, m);
  else return binsearch1(x, m+1, r);
}

int binsearch2(int x, int l, int r) {
  if (l >= r) return r;
  int m = (l + r) / 2;
  if (x < v[m]) return binsearch2(x, l, m);
  else return binsearch2(x, m+1, r);
}

int main() {
  int N, M, K;
  long long A[200000];
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) v.push_back(A[i]);
  sort(v.begin(), v.end());
  long long ans = 0;
  for (int k = 0; k < K; k++) ans += v[k];
  cout << ans;
  for (int i = 1; i <= N - M; i++) {
    int index1 = binsearch1(A[i-1], 0, M-1);
    v.erase(v.begin() + index1);
    int index2 = binsearch2(A[M+i-1], 0, M-1);
    v.insert(v.begin() + index2, A[M+i-1]);
    if (index1 >= K && index2 >= K) ans = ans;
    else if (index1 < K && index2 >= K) ans = ans - A[i-1] + v[K-1];
    else if (index1 >= K && index2 < K) ans = ans - v[K] + A[M+i-1];
    else ans = ans - A[i-1] + A[M+i-1];
    cout << " " << ans;
  }
  cout << endl;
  return 0;
}
