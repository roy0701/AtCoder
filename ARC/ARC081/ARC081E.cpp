#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> vec, int n, int left, int right) {
  int l = left;
  int r = right;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (n == vec[m]) return m;
    else if (n < vec[m]) r = m;
    else l = m;
  }
  return r;
}

int main() {
  string A;
  int alphCount[26];
  vector<int> suffIndex, alphIndex[26];
  cin >> A;
  for (int k = 0; k < 26; k++) alphCount[k] = 0;
  for (int n = 0; n < A.length(); n++) {
    int k = A[n] - 'a';
    alphIndex[k].push_back(n);
    alphCount[k]++;
  }
  int ansLen = 0;
  int alphSet = 0;
  for (int n = A.length() - 1; n >= 0; n--) {
    int k = A[n] - 'a';
    alphSet |= 1 << k;
    if (alphSet == (1 << 26) - 1) {
      suffIndex.push_back(n);
      ansLen++;
      alphSet = 0;
    }
  }
  string ans = "";
  if (ansLen > 0) {
    int n = 0;
    for (int i = ansLen - 1; i >= 0; i--) {
      for (int k = 0; k < 26; k++) {
        int j = binarySearch(alphIndex[k], n, -1, alphCount[k]);
        if (alphIndex[k][j] >= suffIndex[i]) {
          ans += (char) (k + 'a');
          n = alphIndex[k][j] + 1;
          break;
        }
      }
    }
    for (int k = 0; k < 26; k++) {
      if (alphIndex[k][alphCount[k]-1] < n) {
        ans += (char) (k + 'a');
        break;
      }
    }
  } else {
    for (int k = 0; k < 26; k++) {
      if (alphCount[k] == 0) {
        ans += (char) (k + 'a');
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
