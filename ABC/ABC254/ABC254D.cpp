#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int count = 0;
  for (int i = 1; i <= N; i++) {
    int k = i;
    for (int x = 2; x * x <= N; x++) {
      while (k % (x * x) == 0) k /= x * x;
    }
    for (int x = 1; k * x * x <= N; x++) count++;
  }
  cout << count << endl;
  return 0;
}
