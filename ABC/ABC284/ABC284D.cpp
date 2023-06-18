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
  int T;
  long long N, p, q;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;
    for (long long i = 2; true; i++) {
      if (N % i == 0) {
        if (N / i % i == 0) {
          p = i;
          q = N / i / i;
        } else {
          p = sqrt(N / i) + 0.5;
          q = i;
        }
        cout << p << " " << q << endl;
        break;
      }
    }
  }
  return 0;
}
