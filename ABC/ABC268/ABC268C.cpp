#include <iostream>
using namespace std;

int main() {
  int N, p[200000], count[200000];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> p[i];
  for (int i = 0; i < N; i++) count[i] = 0;
  for (int i = 0; i < N; i++) count[(p[i] + N - i) % N]++;
  int m = count[N-1] + count[0] + max(count[N-2], count[1]);
  for (int i = 0; i < N - 2; i++) m = max(m, count[i] + count[i+1] + count[i+2]);
  cout << m << endl;
  return 0;
}
