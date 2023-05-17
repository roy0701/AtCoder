#include <iostream>
using namespace std;

int main() {
  int N, x, y, A[1000];
  bool dpx[20001], dpy[20001], next[20001];
  cin >> N >> x >> y;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int x = 0; x <= 20000; x++) {
    dpx[x] = false;
    dpy[x] = false;
  }
  dpx[A[0]+10000] = true;
  dpy[10000] = true;
  for (int i = 1; i < N; i++) {
    if (i % 2 == 0) {
      for (int z = 0; z <= 20000; z++) {
        next[z] = false;
        if (z + A[i] <= 20000) next[z] |= dpx[z+A[i]];
        if (z - A[i] >= 0) next[z] |= dpx[z-A[i]];
      }
      for (int z = 0; z <= 20000; z++) dpx[z] = next[z];
    } else {
      for (int z = 0; z <= 20000; z++) {
        next[z] = false;
        if (z + A[i] <= 20000) next[z] |= dpy[z+A[i]];
        if (z - A[i] >= 0) next[z] |= dpy[z-A[i]];
      }
      for (int z = 0; z <= 20000; z++) dpy[z] = next[z];
    }
  }
  if (dpx[x+10000] && dpy[y+10000]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
