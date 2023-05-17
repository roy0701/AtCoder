#include <iostream>
using namespace std;

int n[4];

bool find(int i, int res, string exp) {
  if (i == 4) {
    if (res == 7) {
      cout << exp + "=7" << endl;
      return true;
    } else {
      return false;
    }
  }
  if (find(i + 1, res + n[i], exp + "+" + to_string(n[i]))) {
    return true;
  }
  return find(i + 1, res - n[i], exp + "-" + to_string(n[i]));
}

int main() {
  int N;
  cin >> N;
  n[0] = N / 1000;
  n[1] = N / 100 % 10;
  n[2] = N / 10 % 10;
  n[3] = N % 10;
  find(1, n[0], "" + to_string(n[0]));
  return 0;
}
