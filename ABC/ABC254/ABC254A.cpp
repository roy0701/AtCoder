#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = N % 100;
  if (ans < 10) cout << 0;
  cout << ans << endl;
  return 0;
}
