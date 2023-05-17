#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N;
  vector<int> v;
  cin >> N;
  long long n = N;
  for (int k = 0; n > 0; k++) {
    if (n % 2 == 1) v.push_back(k);
    n /= 2;
  }
  for (long long m = 0; m < 1 << v.size(); m++) {
    long long x = 0;
    long long l = m;
    for (int i = 0; l > 0; i++) {
      if (l % 2 == 1) x += (long long) 1 << (long long) v[i];
      l /= 2;
    }
    cout << x << endl;
  }
  return 0;
}
