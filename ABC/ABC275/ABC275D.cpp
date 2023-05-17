#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m;

long long f(long long n) {
  long long x, y;
  if (m.count(n)) return m[n];
  long long ans = f(n / 2) + f(n / 3);
  m.insert({n, ans});
  return ans;
}

int main() {
  long long N;
  cin >> N;
  m.insert({0, 1});
  cout << f(N) << endl;
  return 0;
}
