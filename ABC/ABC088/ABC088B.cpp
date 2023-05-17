#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N;
  int a[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N, greater<int>());
  int Alice = 0;
  int Bob = 0;
  for (int i = 0; i < N; i += 2) {
    Alice += a[i];
    if (i + 1 < N) {
      Bob += a[i + 1];
    }
  }
  cout << Alice - Bob << endl;
  return 0;
}
