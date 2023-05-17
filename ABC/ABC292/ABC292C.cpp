#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long ans = 0;
  for (int A = 1; A < N; A++) {
    for (int B = 1; B <= N / A; B++) {
      int CD = N - A * B;
      int rtCD = sqrt(CD) + 0.5;
      for (int C = 1; C <= rtCD; C++) {
        int D = CD / C;
        if (C * D == CD) {
          ans += C == D ? 1 : 2;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
