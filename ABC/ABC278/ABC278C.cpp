#include <iostream>
#include <map>
using namespace std;

int main() {
  int N, Q, T, A, B;
  map<int,map<int,bool>> follow;
  cin >> N >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> T >> A >> B;
    if (T == 1) {
      follow[A].insert(make_pair(B, true));
    } else if (T == 2) {
      follow[A].erase(B);
    } else {
      if (follow[A].count(B) && follow[A][B] && follow[B].count(A) && follow[A][B]) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}
