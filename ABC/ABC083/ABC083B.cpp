#include <iostream>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    int j = i;
    int s = 0;
    while (j > 0) {
      s += j % 10;
      j /= 10;
    }
    if (A <= s && s <= B) sum += i;
  }
  cout << sum << endl;
  return 0;
}
