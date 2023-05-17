#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int N;
  string S;
  map<string,int> map;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S;
    auto it = map.find(S);
    if (it != map.end()) {
      int X = map.at(S);
      map.erase(S);
      map.insert(make_pair(S, X + 1));
      cout << S << "(" << X << ")" << endl;
    } else {
      map.insert(make_pair(S, 1));
      cout << S << endl;
    }
  }
  return 0;
}
