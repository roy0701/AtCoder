#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long power = 1;
  for (int i = 1; i <= N; i++) {
    power = power * i % 1000000007;
  }
  cout << power << endl;
  return 0;
}
