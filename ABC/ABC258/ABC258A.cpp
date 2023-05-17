#include <iostream>
using namespace std;

int main() {
  int K;
  cin >> K;
  cout << 21 + K / 60 << ":";
  if (K % 60 < 10) cout << "0" << K % 60 << endl;
  else cout << K % 60 << endl;
  return 0;
}
