#include <iostream>
using namespace std;

void print(int n, int k, int a[], int N, int M) {
  if (n == N) {
    for (int i = 0; i < N - 1; i++) {
      cout << a[i] << " ";
    }
    cout << a[N - 1] << endl;
  } else {
    for (int i = k + 1; i <= M; i++) {
      a[n] = i;
      print(n + 1, i, a, N, M);
    }
  }
}

int main() {
  int N, M, a[10];
  cin >> N >> M;
  print(0, 0, a, N, M);
  return 0;
}
