#include <iostream>
using namespace std;

int main() {
  long long A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  long long mod = 998244353;
  long long n1 = ((((A % mod) * (B % mod)) % mod) * (C % mod)) % mod;
  long long n2 = ((((D % mod) * (E % mod)) % mod) * (F % mod)) % mod;
  cout << (n1 + mod - n2) % mod << endl;
  return 0;
}
