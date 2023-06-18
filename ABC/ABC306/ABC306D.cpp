#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#define INF 1000000000000000LL

int main() {
  int N;
  vector<int> X(300001, 0);
  vector<long long> Y(300001, 0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> X[i] >> Y[i];
  }
  vector<long long> good(300001, 0), bad(300001, -INF);
  for (int i = 1; i <= N; i++) {
    if (X[i] == 0) {
      good[i] = max(max(good[i - 1], bad[i - 1]) + Y[i], good[i - 1]);
      bad[i] = bad[i - 1];
    } else if (X[i] == 1) {
      good[i] = good[i - 1];
      bad[i] = max(good[i - 1] + Y[i], bad[i - 1]);
    }
  }
  cout << max(good[N], bad[N]) << endl;
  return 0;
}
