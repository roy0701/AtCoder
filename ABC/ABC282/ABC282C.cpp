#include <iostream>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  cin >> S;
  bool enclosed = false;
  for (int i = 0; i < N; i++) {
    if (S[i] == '\"') enclosed = !enclosed;
    if (!enclosed && S[i] == ',') S[i] = '.';
  }
  cout << S << endl;
  return 0;
}
