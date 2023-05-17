#include <iostream>
#include <set>
using namespace std;

int main() {
  int N;
  int d[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> d[i];
  set<int> s;
  for (int i = 0; i < N; i++) s.insert(d[i]);
  cout << s.size() << endl;
  return 0;
}
