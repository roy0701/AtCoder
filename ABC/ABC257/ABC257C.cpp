#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, W, children[200001], adults[200001];
  string S;
  pair<int,bool> people[200000];
  cin >> N;
  cin >> S;
  for (int i = 0; i < N; i++) {
    cin >> W;
    people[i] = {W, S[i] == '1'};
  }
  sort(people, people + N);
  children[0] = 0;
  adults[N] = 0;
  for (int i = 0; i < N; i++) {
    if (people[i].second == false) children[i+1] = children[i] + 1;
    else children[i+1] = children[i];
    if (people[N-i-1].second == true) adults[N-i-1] = adults[N-i] + 1;
    else adults[N-i-1] = adults[N-i];
  }
  int ans = 0;
  W = 0;
  for (int i = 0; i < N; i++) {
    if (people[i].first > W) {
      ans = max(ans, children[i] + adults[i]);
      W = people[i].first;
    }
  }
  ans = max(ans, children[N] + adults[N]);
  cout << ans << endl;
  return 0;
}
