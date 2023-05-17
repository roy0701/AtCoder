#include <iostream>
using namespace std;

string S;

bool isStanding(int r) {
  switch (r) {
    case 0: return S[6] == '1';
    case 1: return S[3] == '1';
    case 2: return S[1] == '1' || S[7] == '1';
    case 3: return S[0] == '1' || S[4] == '1';
    case 4: return S[2] == '1' || S[8] == '1';
    case 5: return S[5] == '1';
    case 6: return S[9] == '1';
    default: return false;
  }
}

int main() {
  cin >> S;
  bool ans = false;
  if (S[0] == '0') {
    for (int i = 0; i < 5; i++) {
      for (int j = i + 2; j < 7; j++) {
        if (isStanding(i) && isStanding(j)) {
          for (int k = i + 1; k < j; k++) {
            if (!isStanding(k)) {
              ans = true;
              break;
            }
          }
        }
        if (ans) break;
      }
      if (ans) break;
    }
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
