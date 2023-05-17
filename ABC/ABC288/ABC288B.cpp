#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, K;
  string S[100];
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> S[i];
  sort(S, S + K);
  for (int i = 0; i < K; i++) cout << S[i] << endl;
  return 0;
}
