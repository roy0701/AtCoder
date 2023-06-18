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
  int N, A;
  vector<vector<int>> table(100001, vector<int>());
  cin >> N;
  for (int i = 0; i < 3 * N; i++) {
    cin >> A;
    table[A].push_back(i);
  }
  vector<pair<int, int>> fi;
  for (int j = 0; j < N; j++) {
    fi.push_back(make_pair(table[j + 1][1], j + 1));
  }
  sort(fi.begin(), fi.end());
  auto [f, s] = fi[0];
  cout << s;
  for (int j = 1; j < N; j++) {
    auto [f, s] = fi[j];
    cout << " " << s;
  }
  cout << endl;
  return 0;
}
