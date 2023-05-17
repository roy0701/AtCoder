#include <iostream>
using namespace std;

int main() {
  int N;
  string W[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> W[i];
  for (int i = 0; i < N; i++) {
    if (W[i] == "and" || W[i] == "not" || W[i] == "that" || W[i] == "the" ||
        W[i] == "you") {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
