#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int N, M;
vector<string> S(8, "");
vector<string> T;
vector<bool> added(8, false);

bool search(int depth) {
  if (depth == N) {
    for (int i = 0; i < N - 1; i++) {
      int count = 0;
      for (int j = 0; j < M; j++) {
        if (T[i][j] != T[i + 1][j]) {
          count++;
        }
      }
      if (count != 1) {
        return false;
      }
    }
    return true;
  }
  for (int i = 0; i < N; i++) {
    if (!added[i]) {
      added[i] = true;
      T.push_back(S[i]);
      if (search(depth + 1)) {
        return true;
      }
      T.erase(T.end() - 1);
      added[i] = false;
    }
  }
  return false;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  cout << (search(0) ? "Yes" : "No") << endl;
  return 0;
}
