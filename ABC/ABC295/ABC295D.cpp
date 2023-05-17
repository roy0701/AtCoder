#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  vector<int> cnt(1 << 10, 0);
  cin >> S;
  long long ans = 0;
  int v = 0;
  cnt[v]++;
  for (int i = 0; i < (int)S.length(); i++) {
    v ^= (1 << (S[i] - '0'));
    ans += cnt[v];
    cnt[v]++;
  }
  cout << ans << endl;
  return 0;
}
