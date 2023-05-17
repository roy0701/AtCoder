#include <iostream>
using namespace std;

int main() {
  int H1, W1, A[10][10], H2, W2, B[10][10], r[10], c[10];
  cin >> H1 >> W1;
  for (int i = 0; i < H1; i++) {
    for (int j = 0; j < W1; j++) cin >> A[i][j];
  }
  cin >> H2 >> W2;
  for (int i = 0; i < H2; i++) {
    for (int j = 0; j < W2; j++) cin >> B[i][j];
  }
  for (int n = 0; n < 1 << H1; n++) {
    int k = 0;
    int i = 0;
    for (int n0 = n; n0 > 0; n0 /= 2) {
      if (n0 % 2 == 1) {
        r[k] = i;
        k++;
      }
      i++;
    }
    if (k != H2) continue;
    for (int m = 0; m < 1 << W1; m++) {
      int l = 0;
      int j = 0;
      for (int m0 = m; m0 > 0; m0 /= 2) {
        if (m0 % 2 == 1) {
          c[l] = j;
          l++;
        }
        j++;
      }
      if (l != W2) continue;
      bool isSame = true;
      for (i = 0; i < k; i++) {
        for (j = 0; j < l; j++) {
          if (A[r[i]][c[j]] != B[i][j]) {
            isSame = false;
            break;
          }
        }
        if (!isSame) break;
      }
      if (isSame) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
