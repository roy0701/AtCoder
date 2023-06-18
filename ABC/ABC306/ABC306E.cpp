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
  int N, K, Q, X;
  long long Y;
  cin >> N >> K >> Q;
  vector<long long> A(N + 1, 0);
  multiset<long long> greater, lesser;
  for (int j = 0; j < K; j++) {
    greater.insert(0);
  }
  for (int j = K; j < N; j++) {
    lesser.insert(0);
  }
  long long ans = 0;
  for (int i = 0; i < Q; i++) {
    cin >> X >> Y;
    if (K == N) {
      ans = ans - A[X] + Y;
    } else {
      long long g = *(greater.begin());
      auto it = lesser.end();
      it--;
      long long l = *it;
      if (A[X] >= g) {
        greater.erase(greater.find(A[X]));
        if (Y >= l) {
          greater.insert(Y);
          ans = ans - A[X] + Y;
        } else {
          lesser.erase(lesser.find(l));
          greater.insert(l);
          lesser.insert(Y);
          ans = ans - A[X] + l;
        }
      } else {
        lesser.erase(lesser.find(A[X]));
        if (Y >= g) {
          greater.erase(greater.find(g));
          lesser.insert(g);
          greater.insert(Y);
          ans = ans - g + Y;
        } else {
          lesser.insert(Y);
        }
      }
    }
    A[X] = Y;
    cout << ans << endl;
  }
  return 0;
}
