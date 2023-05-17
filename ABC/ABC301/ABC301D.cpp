#include <iostream>
using namespace std;

int main() {
  string S;
  long long N;
  cin >> S;
  cin >> N;
  string T = "";
  for (long long n = N; n > 0; n /= 2) {
    T = (n % 2 ? "1" : "0") + T;
  }
  while (S.length() < T.length()) {
    S = "0" + S;
  }
  while (S.length() > T.length()) {
    T = "0" + T;
  }
  int prev = -1;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == '?' && T[i] == '0') {
      S[i] = '2';
    } else if (S[i] == '?' && T[i] == '1') {
      S[i] = '3';
      prev = i;
    } else if (S[i] == '1' && T[i] == '0') {
      if (prev < 0) {
        cout << -1 << endl;
        return 0;
      }
      S[prev] = '0';
      i = prev + 1;
      while (i < S.length()) {
        if (S[i] == '?' || S[i] == '2') {
          S[i] = '1';
        }
        i++;
      }
    } else if (S[i] == '0' && T[i] == '1') {
      while (i < S.length()) {
        if (S[i] == '?') {
          S[i] = '1';
        }
        i++;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == '2' || S[i] == '3') {
      S[i] -= 2;
    }
    ans = ans * 2 + (S[i] - '0');
  }
  cout << ans << endl;
  return 0;
}
