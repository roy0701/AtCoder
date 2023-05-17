#include <iostream>
using namespace std;

int main() {
  long long X;
  int K;
  cin >> X >> K;
  long long n = 1;
  for (int i = 0; i < K; i++) {
    n *= 10;
    if (X % n >= n / 2) X = (X / n + 1) * n;
    else X = X / n * n;
  }
  cout << X << endl;
  return 0;
}
