#include <iostream>
using namespace std;

int power(int x, int n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    int y = power(x, n / 2);
    return y * y;
  } else {
    return x * power(x, n - 1);
  }
}

int main() {
  int N;
  cin >> N;
  cout << power(2, N) << endl;
  return 0;
}
