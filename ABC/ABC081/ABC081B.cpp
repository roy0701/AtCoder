#include <iostream>
using namespace std;

int main() {
  int N;
  int A[200];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  int count = 0;
  while (true) {
    bool flag = false;
    for (int i = 0; i < N; i++) {
      if (A[i] % 2 == 0) {
        A[i] /= 2;
      } else {
        flag = true;
        break;
      }
    }
    if (flag) {
      cout << count << endl;
      return 0;
    } else {
      count++;
    }
  }
}
