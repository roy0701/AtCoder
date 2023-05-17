#include <iostream>
using namespace std;

int main() {
  int len = 7;
  int a[len];
  string S;
  cin >> S;
  for (int i = 0; i < len; i++) {
    switch (S[i]) {
      case 'a':
        a[i] = 0;
        break;
      case 't':
        a[i] = 1;
        break;
      case 'c':
        a[i] = 2;
        break;
      case 'o':
        a[i] = 3;
        break;
      case 'd':
        a[i] = 4;
        break;
      case 'e':
        a[i] = 5;
        break;
      case 'r':
        a[i] = 6;
        break;
      default: break;
    }
  }
  int ans = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (a[j] > a[j+1]) {
        int tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
