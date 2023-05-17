#include <iostream>
using namespace std;

int b[2][3], c[3][2], board[3][3];

int dfs(int n) {
  if (n == 9) {
    int score = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == board[i+1][j]) score += b[i][j];
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        if (board[i][j] == board[i][j+1]) score += c[i][j];
      }
    }
    return score;
  } else {
    int player = n % 2;
    int bestScore = player == 0 ? -1 : 2e9;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] < 0) {
          board[i][j] = player;
          int score = dfs(n + 1);
          if (player == 0 && score > bestScore) bestScore = score;
          else if (player == 1 && score < bestScore) bestScore = score;
          board[i][j] = -1;
        }
      }
    }
    return bestScore;
  }
}

int main() {
  int sum = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> b[i][j];
      sum += b[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> c[i][j];
      sum += c[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) board[i][j] = -1;
  }
  int score = dfs(0);
  cout << score << endl;
  cout << sum - score << endl;
  return 0;
}
