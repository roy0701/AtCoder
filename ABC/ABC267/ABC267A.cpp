#include <iostream>
using namespace std;

int main() {
  string S;
  int ans;
  cin >> S;
  if (S == "Monday") ans = 5;
  else if (S == "Tuesday") ans = 4;
  else if (S == "Wednesday") ans = 3;
  else if (S == "Thursday") ans = 2;
  else if (S == "Friday") ans = 1;
  cout << ans << endl;
  return 0;
}
