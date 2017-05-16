#include <iostream>

using namespace std;

struct Board {
  char pos[10][10];
  int x;
};

int n;   // size of Board
int ans; // number of answers

void DFS(Board tmp, int k) {
  if (k == 0) {
    ans++;
    return;
  }
  int i, j;
  for (i = tmp.x + 1; i <= n - k; i++) {
    for (j = 0; j < n; j++) {
      if (tmp.pos[i][j] == '#') {
        Board tmp2;
        tmp2 = tmp;
        tmp2.x = i;
        int l;
        for (l = i + 1; l < n; l++) {
          tmp2.pos[l][j] = '.';
        }
        DFS(tmp2, k - 1);
      }
    }
  }
}

int main() {
  int k;
  while (cin >> n >> k, n != -1 || k != -1) {
    ans = 0;
    Board board;
    board.x = -1;
    int i;
    for (i = 0; i < n; i++) {
      cin >> board.pos[i];
    }
    DFS(board, k);
    cout << ans << endl;
  }
  return 0;
}
