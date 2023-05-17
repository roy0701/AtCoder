#include <iostream>
using namespace std;

int main() {
  int N, X, p, k;
  cin >> N >> X;
  for (int i = 0; i < N; i++) {
    cin >> p;
    if (p == X) k = i+1;
  }
  cout << k << endl;
  return 0;
}
