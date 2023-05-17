#include <iostream>
#include <queue>
using namespace std;

int main() {
  int N, a[300000];
  long long sumFirst[100001], sumSecond[100001];
  cin >> N;
  for (int i = 0; i < 3 * N; i++) cin >> a[i];
  priority_queue<int, vector<int>, greater<int>> first;
  priority_queue<int> second;
  for (int i = 0; i < N; i++) {
    first.push(a[i]);
    sumFirst[0] += a[i];
  }
  for (int i = 0; i < N; i++) {
    first.push(a[N + i]);
    sumFirst[i + 1] = sumFirst[i] + a[N + i] - first.top();
    first.pop();
  }
  for (int i = 2 * N; i < 3 * N; i++) {
    second.push(a[i]);
    sumSecond[N] += a[i];
  }
  for (int i = N - 1; i >= 0; i--) {
    second.push(a[N + i]);
    sumSecond[i] = sumSecond[i + 1] + a[N + i] - second.top();
    second.pop();
  }
  long long score = sumFirst[0] - sumSecond[0];
  for (int i = 1; i <= N; i++) score = max(score, sumFirst[i] - sumSecond[i]);
  cout << score << endl;
  return 0;
}
