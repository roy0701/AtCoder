#include <iostream>
#include <vector>
using namespace std;

int main() {
  int R, C;
  char B[20][20];
  vector<int> bombi, bombj;
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> B[i][j];
      if ('1' <= B[i][j] && B[i][j] <= '9') {
        bombi.push_back(i);
        bombj.push_back(j);
      }
    }
  }
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (B[i][j] == '#') {
        bool empty = false;
        for (int k = 0; k < bombi.size(); k++) {
          int bi = bombi[k];
          int bj = bombj[k];
          if (abs(i - bi) + abs(j - bj) <= B[bi][bj] - '0') {
            empty = true;
            break;
          }
        }
        cout << (empty ? "." : "#");
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
  return 0;
}
