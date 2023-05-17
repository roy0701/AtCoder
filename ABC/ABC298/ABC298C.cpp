#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, Q, k, i, j;
  map<int, vector<int>> box;
  map<int, set<int>> num;
  cin >> N;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    cin >> k;
    if (k == 1) {
      cin >> i >> j;
      box[j].push_back(i);
      num[i].insert(j);
    } else if (k == 2) {
      cin >> i;
      sort(box[i].begin(), box[i].end());
      for (int l = 0; l < box[i].size(); l++) {
        if (l > 0) {
          cout << " ";
        }
        cout << box[i][l];
      }
      cout << endl;
    } else if (k == 3) {
      cin >> i;
      set<int>::iterator it = num[i].begin();
      cout << *it;
      it++;
      while (it != num[i].end()) {
        cout << " " << *it;
        it++;
      }
      cout << endl;
    }
  }
  return 0;
}
