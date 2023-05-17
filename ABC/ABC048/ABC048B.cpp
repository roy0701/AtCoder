#include <iostream>
using namespace std;

int main() {
  long long a, b, x;
  cin >> a >> b >> x;
  long long ans = b / x - a / x;
  if (a % x == 0) ans++;
  cout << ans << endl;
  return 0;
}
