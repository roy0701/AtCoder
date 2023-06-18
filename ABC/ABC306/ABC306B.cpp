#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

int main() {
  vector<int> A(64, 0);
  for (int i = 0; i < 64; i++) {
    cin >> A[i];
  }
  cpp_int ans = 0;
  cpp_int one = 1;
  cpp_int two = 2;
  for (int i = 63; i >= 0; i--) {
    if (A[i] == 0) {
      ans = ans * two;
    } else if (A[i] == 1) {
      ans = ans * two + one;
    }
  }
  cout << ans << endl;
  return 0;
}
