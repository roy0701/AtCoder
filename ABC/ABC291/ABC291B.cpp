#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int N, X[500];
  cin >> N;
  for (int i = 0; i < 5 * N; i++) {
    cin >> X[i];
  }
  sort(X, X + 5 * N);
  double sum = 0;
  for (int i = N; i < 4 * N; i++) {
    sum += X[i];
  }
  cout << setprecision(15) << sum / (3 * N) << endl;
  return 0;
}
