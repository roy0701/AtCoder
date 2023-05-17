#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int H, W;
  char S[400000], T[400000];
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> S[i * W + j];
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> T[i * W + j];
  }
  string A[W], B[W];
  for (int j = 0; j < W; j++) {
    string str = "";
    for (int i = 0; i < H; i++) str += S[i * W + j];
    A[j] = str;
    str = "";
    for (int i = 0; i < H; i++) str += T[i * W + j];
    B[j] = str;
  }
  sort(A, A + W);
  sort(B, B + W);
  for (int j = 0; j < W; j++) {
    if (A[j] != B[j]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
