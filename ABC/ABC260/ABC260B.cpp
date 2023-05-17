#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
  int number, score;
};

bool operator<(const Student& s1, const Student& s2) noexcept {
  return s1.score > s2.score || (s1.score == s2.score && s1.number < s2.number);
}

int main() {
  int N, X, Y, Z, A[1000], B[1000], numbers[1000];
  Student students[1000];
  cin >> N >> X >> Y >> Z;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) {
    students[i].number = i;
    students[i].score = A[i];
  }
  sort(students, students + N);
  for (int i = 0; i < N; i++) students[i].score = B[students[i].number];
  sort(students + X, students + N);
  for (int i = 0; i < N; i++) students[i].score = A[students[i].number] + B[students[i].number];
  sort(students + X + Y, students + N);
  for (int i = 0; i < X + Y + Z; i++) numbers[i] = students[i].number + 1;
  sort(numbers, numbers + X + Y + Z);
  for (int i = 0; i < X + Y + Z; i++) cout << numbers[i] << endl;
  return 0;
}
