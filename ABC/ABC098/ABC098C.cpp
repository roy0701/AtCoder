#include <iostream>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  int west [300000], east[300000];
  west[0] = (S[0] == 'W');
  east[N - 1] = (S[N - 1] == 'E');
  for (int i = 1; i < N; i++) {
    west[i] = west[i - 1] + (S[i] == 'W');
    east[N - i - 1] = east[N - i] + (S[N - i - 1] == 'E');
  }
  int m = min(east[1], west[N - 1]);
  for (int i = 1; i < N - 1; i++) {
    m = min(m, west[i - 1] + east[i + 1]);
  }
  cout << m << endl;
  return 0;
}
