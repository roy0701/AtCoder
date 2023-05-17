#include <iostream>
#include <map>
using namespace std;

int main() {
  string S, T;
  map<char, int> smap, tmap;
  cin >> S >> T;
  for (char c = 'a'; c <= 'z'; c++) {
    smap[c] = 0;
    tmap[c] = 0;
  }
  smap['@'] = 0;
  tmap['@'] = 0;
  int n = S.length();
  for (int i = 0; i < n; i++) {
    smap[S[i]]++;
    tmap[T[i]]++;
  }
  bool ans = true;
  for (char c = 'a'; c <= 'z'; c++) {
    if (c == 'a' || c == 't' || c == 'c' || c == 'o' || c == 'd' || c == 'e' ||
        c == 'r') {
      if (smap[c] > tmap[c]) {
        tmap['@'] -= smap[c] - tmap[c];
        ans = tmap['@'] >= 0;
      } else if (smap[c] < tmap[c]) {
        smap['@'] -= tmap[c] - smap[c];
        ans = smap['@'] >= 0;
      }
    } else {
      ans = smap[c] == tmap[c];
    }
    if (!ans) {
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
