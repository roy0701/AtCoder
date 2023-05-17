#include <iostream>
using namespace std;

int main() {
  int N, Q, L[200000], left[200000], a[200000], s, t;
  cin >> N >> Q;
  int x = 0;
  for (int i = 0; i < N; i++) {
    cin >> L[i];
    left[i] = i == 0 ? 0 : (left[i-1] + L[i-1]);
    for (int j = 0; j < L[i]; j++) {
      cin >> a[x];
      x++;
    }
  }
  for (int k = 0; k < Q; k++) {
    cin >> s >> t;
    cout << a[left[s-1] + t-1] << endl;
  }
  return 0;
}
