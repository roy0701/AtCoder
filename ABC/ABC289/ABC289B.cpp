#include <iostream>
using namespace std;

int main() {
  int N, M, a[100];
  bool read[101];
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a[i];
  }
  read[0] = true;
  for (int j = 1; j <= N; j++) {
    read[j] = false;
  }
  int i = 0;
  int cnt = 0;
  for (int j = 1; j <= N; j++) {
    if (a[i] == j) {
      i++;
    } else {
      for (int k = j; !read[k]; k--) {
        cout << k;
        if (cnt < N - 1) cout << " ";
        cnt++;
        read[k] = true;
      }
    }
  }
  cout << endl;
  return 0;
}
