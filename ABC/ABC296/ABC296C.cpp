#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  long long N, X, a;
  vector<long long> A;
  cin >> N >> X;
  for (int i = 0; i < N; i++) {
    cin >> a;
    A.push_back(a);
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < N; i++) {
    if (binary_search(A.begin(), A.end(), A[i] + X)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
