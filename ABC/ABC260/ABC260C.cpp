#include <iostream>
using namespace std;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  long long red = 1;
  long long blue = 0;
  for (int n = N; n > 1; n--) {
    blue += X * red;
    red += blue;
    blue = Y * blue;
  }
  cout << blue << endl;
  return 0;
}
