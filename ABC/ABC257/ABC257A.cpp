#include <iostream>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  char ans = X / N + 'A';
  if (X % N == 0) ans--;
  cout << ans << endl;
  return 0;
}
