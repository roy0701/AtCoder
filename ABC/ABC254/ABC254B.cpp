#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, a[30][30];
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 | j == i) a[i][j] = 1;
      else a[i][j] = a[i-1][j-1] + a[i-1][j];
      if (j < i) cout << a[i][j] << " ";
      else cout << a[i][j] << endl;
    }
  }
  return 0;
}
