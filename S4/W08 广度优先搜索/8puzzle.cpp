#include <bitset>
#include <cstring>
#include <iostream>

using namespace std;

int goalStatus;
bitset<362880> Flags;
const int MAXS = 400000;
char result[MAXS];

struct Node {
  int status;
  int father;
  char move;
  Node(int s, int f, char m) : status(s), father(f), move(m) {}
  Node() {}
};

Node myQueue[MAXS];
int qHead;
int qTail;
char sz4Moves[] = "udrl";
unsigned int factorial[21];

unsigned int GetPermutationNumForInt(int *perInt, int len) {
  unsigned int num = 0;
  bool used[21];
  memset(used, 0, sizeof(bool) * len);
  for (int i = 0; i < len; ++i) {
    unsigned int n = 0;
    for (int j = 0; j < perInt[i]; ++j) {
      if (!used[j])
        ++n;
    }
    num += n * factorial[len - i - 1];
    used[perInt[i]] = true;
  }
  return num;
}

template <class T> unsigned int GetPermutationNum(T s1, T s2, int len) {
  int perInt[21];
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len; ++j) {
      if (*(s2 + i) == *(s1 + j)) {
        perInt[i] = j;
        break;
      }
    }
  }
  unsigned int num = GetPermutationNumForInt(perInt, len);
  return num;
}

template <class T>
void GenPermutationByNum(T s1, T s2, int len, unsigned int No) {
  int perInt[21];
  bool used[21];
  memset(used, 0, sizeof(bool) * len);
  for (int i = 0; i < len; ++i) {
    unsigned int tmp;
    int n = 0;
    int j;
    for (j = 0; j < len; ++j) {
      if (!used[j]) {
        if (factorial[len - i - 1] >= No + 1)
          break;
        else
          No -= factorial[len - i - 1];
      }
    }
    perInt[i] = j;
    used[j] = true;
  }
  for (int i = 0; i < len; ++i)
    *(s2 + i) = *(s1 + perInt[i]);
}

int StrStatusToIntStatus(const char *strStatus) {
  return GetPermutationNum("012345678", strStatus, 9);
}

void IntStatusToStrStatus(int n, char *strStatus) {
  GenPermutationByNum((char *)"012345678", strStatus, 9, n);
}

int NewStatus(int nStatus, char cMove) {
  char szTmp[20];
  int nZeroPos;
  IntStatusToStrStatus(nStatus, szTmp);
  for (int i = 0; i < 9; ++i) {
    if (szTmp[i] == '0') {
      nZeroPos = i;
      break;
    }
  }
  switch (cMove) {
  case 'u':
    if (nZeroPos - 3 < 0)
      return -1;
    else {
      szTmp[nZeroPos] = szTmp[nZeroPos - 3];
      szTmp[nZeroPos - 3] = '0';
    }
    break;
  case 'd':
    if (nZeroPos + 3 > 8)
      return -1;
    else {
      szTmp[nZeroPos] = szTmp[nZeroPos + 3];
      szTmp[nZeroPos + 3] = '0';
    }
    break;
  case 'l':
    if (nZeroPos % 3 == 0)
      return -1;
    else {
      szTmp[nZeroPos] = szTmp[nZeroPos - 1];
      szTmp[nZeroPos - 1] = '0';
    }
    break;
  case 'r':
    if (nZeroPos % 3 == 2)
      return -1;
    else {
      szTmp[nZeroPos] = szTmp[nZeroPos + 1];
      szTmp[nZeroPos + 1] = '0';
    }
    break;
  }
  return StrStatusToIntStatus(szTmp);
}

bool Bfs(int nStatus) {
  int nNewStatus;
  Flags.reset();
  qHead = 0;
  qTail = 1;
  myQueue[qHead] = Node(nStatus, -1, 0);
  while (qHead != qTail) {
    nStatus = myQueue[qHead].status;
    if (nStatus == goalStatus)
      return true;
    for (int i = 0; i < 4; i++) {
      nNewStatus = NewStatus(nStatus, sz4Moves[i]);
      if (nNewStatus == -1)
        continue;
      if (Flags[nNewStatus])
        continue;
      Flags.set(nNewStatus, true);
      myQueue[qTail++] = Node(nNewStatus, qHead, sz4Moves[i]);
    }
    qHead++;
  }
  return false;
}

int main() {
  factorial[0] = factorial[1] = 1;
  for (int i = 2; i < 21; ++i)
    factorial[i] = i * factorial[i - 1];
  goalStatus = StrStatusToIntStatus("123456780");
  char szLine[50];
  char szLine2[20];
  while (cin.getline(szLine, 48)) {
    int i, j;
    for (i = 0, j = 0; szLine[i]; i++) {
      if (szLine[i] != ' ') {
        if (szLine[i] == 'x')
          szLine2[j++] = '0';
        else
          szLine2[j++] = szLine[i];
      }
    }
    szLine2[j] = 0;
    int sumGoal = 0;
    for (int i = 0; i < 8; ++i)
      sumGoal += i - 1;
    int sumOri = 0;
    for (int i = 0; i < 9; ++i) {
      if (szLine2[i] == '0')
        continue;
      for (int j = 0; j < i; ++j) {
        if (szLine2[j] < szLine2[i] && szLine2[j] != '0')
          sumOri++;
      }
    }

    if (sumOri % 2 != sumGoal % 2) {
      cout << "unsolvable" << endl;
      continue;
    }

    if (Bfs(StrStatusToIntStatus(szLine2))) {
      int nMoves = 0;
      int nPos = qHead;
      do {
        result[nMoves++] = myQueue[nPos].move;
        nPos = myQueue[nPos].father;
      } while (nPos);
      for (int i = nMoves - 1; i >= 0; i--)
        cout << result[i];
    } else
      cout << "unsolvable" << endl;
  }
  return 0;
}
