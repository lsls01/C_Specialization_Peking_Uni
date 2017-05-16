#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

int R, C;
int rooms[60][60];
int color[60][60];
int maxRoomArea = 0, roomNum = 0;
int roomArea;

void Dfs(int r, int c) {
  struct Room {
    int r, c;
    Room(int rr, int cc) : r(rr), c(cc) {}
  };
  stack<Room> stk;
  stk.push(Room(r, c));
  while (!stk.empty()) {
    Room rm = stk.top();
    int i = rm.r;
    int k = rm.c;
    if (color[i][k])
      stk.pop();
    else {
      ++roomArea;
      color[i][k] = roomNum;
      if ((rooms[i][k] & 1) == 0)
        stk.push(Room(i, k - 1));
      if ((rooms[i][k] & 2) == 0)
        stk.push(Room(i - 1, k));
      if ((rooms[i][k] & 4) == 0)
        stk.push(Room(i, k + 1));
      if ((rooms[i][k] & 8) == 0)
        stk.push(Room(i + 1, k));
    }
  }
}

int main() {
  cin >> R >> C;
  for (int i = 1; i <= R; ++i)
    for (int k = 1; k <= C; ++k)
      cin >> rooms[i][k];

  memset(color, 0, sizeof(color));

  for (int i = 1; i <= R; ++i)
    for (int k = 1; k <= C; ++k) {
      if (!color[i][k]) {
        ++roomNum;
        Dfs(i, k);
        maxRoomArea = max(roomArea, maxRoomArea);
      }
    }

  cout << roomNum << endl;
  cout << maxRoomArea << endl;
}
