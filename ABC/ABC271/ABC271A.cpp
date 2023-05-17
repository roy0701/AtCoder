#include <iostream>
using namespace std;

void print16(int n) {
  if (n < 10) cout << n;
  else cout << (char) (n - 10 + 'A');
}

int main() {
  int N, a, b;
  cin >> N;
  a = N / 16;
  b = N % 16;
  print16(a);
  print16(b);
  cout << endl;
  return 0;
}
