#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
  long long A, B;
  cin >> A >> B;
  long long ans = A / B;
  if (A % B > 0) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
