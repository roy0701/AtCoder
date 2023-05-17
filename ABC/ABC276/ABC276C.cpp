#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, P[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> P[i];
  vector<int> vec = {P[N-1]};
  int j = N-2;
  while (P[j] < vec[vec.size()-1]) {
    vec.push_back(P[j]);
    j--;
  }
  vec.push_back(P[j]);
  sort(vec.begin(), vec.end());
  int size = N - j;
  int k = 0;
  while (vec[k] < P[j]) k++;
  for (int i = 0; i < j; i++) cout << P[i] << " ";
  cout << vec[k-1];
  for (int l = size-1; l >= 0; l--) {
    if (l != k-1) cout << " " << vec[l];
  }
  cout << endl;
  return 0;
}
