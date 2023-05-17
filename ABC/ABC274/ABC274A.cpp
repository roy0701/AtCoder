#include <iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int n = 10000 * B / A;
  cout << n / 10000;
  cout << ".";
  cout << n / 1000 % 10;
  cout << n / 100 % 10;
  cout << n / 10 % 10 + (n % 10 >= 5 ? 1 : 0) << endl;
  return 0;
}
