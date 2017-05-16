#include <algorithm>
#include <iostream>

using namespace std;

struct dot {
  int col;
  int row;
  int height;
};
dot matrix[101 * 101], original[101][101];

int col, row;
int length[101][101];

bool compare(dot lhs, dot rhs) { return lhs.height < rhs.height; }

int maxStep(int i) {
  int maxStep = 1;
  for (int j = 0; j < i; ++j) {
    int r = matrix[j].row;
    int c = matrix[j].col;
    int h = matrix[j].height;
    if (r > 1 && original[r - 1][c].height > h) {
      length[r - 1][c] = max(length[r - 1][c], length[r][c] + 1);
      if (length[r - 1][c] > maxStep) {
        maxStep = length[r - 1][c];
      }
    }
    if (r < row && original[r + 1][c].height > h) {
      length[r + 1][c] = max(length[r + 1][c], length[r][c] + 1);
      if (length[r + 1][c] > maxStep) {
        maxStep = length[r + 1][c];
      }
    }
    if (c > 1 && original[r][c - 1].height > h) {
      length[r][c - 1] = max(length[r][c - 1], length[r][c] + 1);
      if (length[r][c - 1] > maxStep) {
        maxStep = length[r][c - 1];
      }
    }
    if (c < col && original[r][c + 1].height > h) {
      length[r][c + 1] = max(length[r][c + 1], length[r][c] + 1);
      if (length[r][c + 1] > maxStep) {
        maxStep = length[r][c + 1];
      }
    }
  }
  return maxStep;
}

int main() {
  cin >> row >> col;
  int k = 0;
  for (int i = 1; i < row + 1; ++i) {
    for (int j = 1; j < col + 1; ++j) {
      matrix[k].row = i;
      matrix[k].col = j;
      cin >> matrix[k].height;
      original[i][j] = matrix[k];
      length[i][j] = 1;
      k++;
    }
  }
  sort(matrix, matrix + k, compare);
  int maxLength = maxStep(k);
  cout << maxLength;
  return 0;
}
