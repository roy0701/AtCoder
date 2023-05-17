#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
string S[8];
vector<string> T(100000);
bool contain[8];

string enumerate(int k, string name, int c) {
  if (k == N) {
    if (name.length() >= 3 && !binary_search(T.begin(), T.end(), name)) return name;
    else return "";
  } else {
    for (int i = 0; i < N; i++) {
      if (!contain[i]) {
        contain[i] = true;
        if (k == 0) {
          string validName = enumerate(1, S[i], c);
          if (validName != "") return validName;
        } else {
          string newName = name;
          for (int u = 0; u <= c; u++) {
            newName += "_";
            string validName = enumerate(k + 1, newName + S[i], c - u);
            if (validName != "") return validName;
          }
        }
        contain[i] = false;
      }
    }
    return "";
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> S[i];
  for (int j = 0; j < M; j++) cin >> T[j];
  sort(T.begin(), T.end());
  int length = 0;
  for (int i = 0; i < N; i++) {
    contain[i] = false;
    length += S[i].length();
  }
  string name = enumerate(0, "", 17 - N - length);
  if (name == "") cout << -1 << endl;
  else cout << name << endl;
  return 0;
}
