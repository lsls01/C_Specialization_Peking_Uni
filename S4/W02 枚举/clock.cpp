#include <iostream>

using namespace std;

int check(int a[]) {
  for (int i = 1; i <= 9; i++)
    if (a[i] != 0)
      return 0;
  return 1;
}

void nextop(int a[], int op[]) {
  int t = 3;
  op[t]++;
  while (op[t] > 3) {
    op[t] %= 4;
    op[t - 1]++;
    t--;
  }
  op[4] = 36 - a[1] - op[1] - op[2];
  op[4] %= 4;
  op[5] = 36 - a[2] - op[1] - op[2] - op[3];
  op[5] %= 4;
  op[6] = 36 - a[3] - op[2] - op[3];
  op[6] %= 4;
  op[7] = 36 - a[4] - op[1] - op[4] - op[5];
  op[7] %= 4;
  op[8] = 36 - a[7] - op[4] - op[7];
  op[8] %= 4;
  op[9] = 36 - a[9] - op[6] - op[8];
  op[9] %= 4;
}

void move(int a[], char t) {
  a[t - 'A' + 1]++;
  a[t - 'A' + 1] %= 4;
}

void fun(int a[], int op[]) {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= op[i]; j++) {
      switch (i) {
      case 1:
        move(a, 'A');
        move(a, 'B');
        move(a, 'D');
        move(a, 'E');
        break;
      case 2:
        move(a, 'A');
        move(a, 'B');
        move(a, 'C');
        break;
      case 3:
        move(a, 'B');
        move(a, 'C');
        move(a, 'E');
        move(a, 'F');
        break;
      case 4:
        move(a, 'A');
        move(a, 'D');
        move(a, 'G');
        break;
      case 5:
        move(a, 'B');
        move(a, 'D');
        move(a, 'E');
        move(a, 'F');
        move(a, 'H');
        break;
      case 6:
        move(a, 'C');
        move(a, 'F');
        move(a, 'I');
        break;
      case 7:
        move(a, 'D');
        move(a, 'E');
        move(a, 'G');
        move(a, 'H');
        break;
      case 8:
        move(a, 'G');
        move(a, 'H');
        move(a, 'I');
        break;
      case 9:
        move(a, 'E');
        move(a, 'F');
        move(a, 'H');
        move(a, 'I');
        break;
      }
    }
  }
}

int main() {
  int a[11] = {0};
  for (int i = 1; i <= 9; i++)
    cin >> a[i];
  int op[11] = {0};
  op[3] = -1;
  nextop(a, op);
  while (true) {
    int b[11];
    for (int i = 1; i <= 9; i++)
      b[i] = a[i];
    fun(b, op);
    if (check(b))
      break;
    nextop(a, op);
  }
  int ans[50] = {0};
  int top = 0;
  for (int i = 1; i <= 9; i++)
    for (int j = 1; j <= op[i]; j++) {
      ans[top++] = i;
    }
  cout << ans[0];
  for (int i = 1; i < top; i++)
    cout << " " << ans[i];
  cout << endl;
  return 0;
}
