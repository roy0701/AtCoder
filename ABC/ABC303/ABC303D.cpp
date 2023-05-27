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
  long long X, Y, Z;
  string S;
  cin >> X >> Y >> Z;
  cin >> S;
  long long on = 100000000000000000;
  long long off = 0;
  for (int i = 0; i < S.length(); i++) {
    long long newOn, newOff;
    if (S[i] == 'A') {
      newOn = min(on + X, off + Z + X);
      newOff = min(off + Y, on + Z + Y);
    } else if (S[i] == 'a') {
      newOn = min(on + Y, off + Z + Y);
      newOff = min(off + X, on + Z + X);
    }
    on = newOn;
    off = newOff;
  }
  cout << min(on, off) << endl;
  return 0;
}
