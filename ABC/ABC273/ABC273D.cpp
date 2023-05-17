#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int H, W, rs, cs, N, r, c, Q, l;
  char d;
  map<int, vector<int>> rwalls, cwalls;
  cin >> H >> W >> rs >> cs;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> r >> c;
    rwalls[r].push_back(c);
    cwalls[c].push_back(r);
  }
  for (auto it = rwalls.begin(); it != rwalls.end(); it++) sort((it->second).begin(), (it->second).end());
  for (auto it = cwalls.begin(); it != cwalls.end(); it++) sort((it->second).begin(), (it->second).end());
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    cin >> d >> l;
    if (d == 'L') {
      auto it = rwalls.find(rs);
      c = 0;
      if (it != rwalls.end()) {
        auto it2 = lower_bound((it->second).begin(), (it->second).end(), cs);
        if (it2 != (it->second).begin()) c = *(it2 - 1);
      }
      cs = max(cs - l, c + 1);
    } else if (d == 'R') {
      auto it = rwalls.find(rs);
      c = W + 1;
      if (it != rwalls.end()) {
        auto it2 = upper_bound((it->second).begin(), (it->second).end(), cs);
        if (it2 != (it->second).end()) c = *it2;
      }
      cs = min(cs + l, c - 1);
    } else if (d == 'U') {
      auto it = cwalls.find(cs);
      r = 0;
      if (it != cwalls.end()) {
        auto it2 = lower_bound((it->second).begin(), (it->second).end(), rs);
        if (it2 != (it->second).begin()) r = *(it2 - 1);
      }
      rs = max(rs - l, r + 1);
    } else if (d == 'D') {
      auto it = cwalls.find(cs);
      r = H + 1;
      if (it != cwalls.end()) {
        auto it2 = upper_bound((it->second).begin(), (it->second).end(), rs);
        if (it2 != (it->second).end()) r = *it2;
      }
      rs = min(rs + l, r - 1);
    }
    cout << rs << " " << cs << endl;
  }
  return 0;
}
