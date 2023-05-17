#include <iostream>
using namespace std;

int N;
string S, T;

void swap(int i, int j) {
  char tmp = T[i];
  T[i] = T[j];
  T[j] = tmp;
}

int minCharIndex(int i, char infc) {
  int ans;
  char minc = 'z' + 1;
  for (int j = i; j < N; j++) {
    char tj = T[j];
    if (infc <= tj && tj < minc) {
      ans = j;
      minc = tj;
    }
  }
  return ans;
}

int countDifferentChars(int i) {
  int a[26], b[26];
  for (int n = 0; n < 26; n++) {
    a[n] = 0;
    b[n] = 0;
  }
  for (int j = i; j < N; j++) {
    a[S[j] - 'a']++;
    b[T[j] - 'a']++;
  }
  int count = 0;
  for (int n = 0; n < 26; n++) count += max(a[n] - b[n], 0);
  return count;
}

int main() {
  int K;
  cin >> N >> K;
  cin >> S;
  T = S;
  int i = 0;
  int k = K;
  char infc = 'a';
  while (i < N && k > 0) {
    int j = minCharIndex(i, infc);
    swap(i, j);
    if (T[i] == S[i]) {
      i++;
      infc = 'a';
    } else if (countDifferentChars(i+1) <= k-1) {
      i++;
      k--;
      infc = 'a';
    } else {
      infc = T[i] + 1;
      swap(i, j);
    }
  }
  cout << T << endl;
  return 0;
}
