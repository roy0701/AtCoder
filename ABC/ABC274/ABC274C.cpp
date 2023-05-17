#include <iostream>
using namespace std;

int main() {
  int N, a, parent[400002], ans[400002];
  cin >> N;
  parent[1] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> a;
    parent[2*i] = a;
    parent[2*i+1] = a;
  }
  ans[0] = -1;
  for (int k = 1; k <= 2 * N + 1; k++) {
    ans[k] = ans[parent[k]] + 1;
    cout << ans[k] << endl;
  }
  return 0;
}
