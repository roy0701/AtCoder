#include <iostream>
#include <queue>
using namespace std;

#define MOD 998244353

long long power10(long long n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    long long y = power10(n / 2);
    return (y * y) % MOD;
  } else {
    long long y = power10(n - 1);
    return (y * 10) % MOD;
  }
}

int main() {
  int Q, k, x;
  cin >> Q;
  queue<int> S;
  S.push(1);
  long long num = 1;
  long long d = 0;
  for (int q = 0; q < Q; q++) {
    cin >> k;
    if (k == 1) {
      cin >> x;
      S.push(x);
      num = (num * 10 + x) % MOD;
      d++;
    } else if (k == 2) {
      x = S.front();
      S.pop();
      num = (num - power10(d) * x) % MOD;
      num = (num + MOD) % MOD;
      d--;
    } else if (k == 3) {
      cout << num << endl;
    }
  }
  return 0;
}
