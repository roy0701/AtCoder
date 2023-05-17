#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main() {
  int N, A, B;
  map<int,vector<int>> edges;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A >> B;
    if (edges.count(A)) edges[A].push_back(B);
    else edges[A] = {B};
    if (edges.count(B)) edges[B].push_back(A);
    else edges[B] = {A};
  }
  vector<int> reachable = {1};
  set<int> reachableSet = {1};
  for (int i = 0; i < reachable.size(); i++) {
    vector<int> next = edges[reachable[i]];
    for (int j = 0; j < next.size(); j++) {
      if (!reachableSet.count(next[j])) {
        reachable.push_back(next[j]);
        reachableSet.insert(next[j]);
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < reachable.size(); i++) ans = max(ans, reachable[i]);
  cout << ans << endl;
  return 0;
}
