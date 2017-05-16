#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int N;
int L;
vector<int> anLength;
int anUsed[65];
int i, j, k;
int nLastStickNo;
int Dfs(int R, int M);

int main() {
  while (1) {
    cin >> N;
    if (N == 0)
      break;
    int nTotalLen = 0;
    anLength.clear();
    for (int i = 0; i < N; i++) {
      int n;
      cin >> n;
      anLength.push_back(n);
      nTotalLen += anLength[i];
    }
    sort(anLength.begin(), anLength.end(), greater<int>());
    for (L = anLength[0]; L <= nTotalLen / 2; L++) {
      if (nTotalLen % L)
        continue;
      memset(anUsed, 0, sizeof(anUsed));
      if (Dfs(N, L)) {
        cout << L << endl;
        break;
      }
    }
    if (L > nTotalLen / 2)
      cout << nTotalLen << endl;
  }
  return 0;
}

int Dfs(int nUnusedSticks, int nLeft) {
  if (nUnusedSticks == 0 && nLeft == 0)
    return true;
  if (nLeft == 0)
    nLeft = L;
  int nStartNo = 0;
  if (nLeft != L)
        nStartNo = nLastStickNo + 1;
  for (int i = nStartNo; i < N; i++) {
    if (!anUsed[i] && anLength[i] <= nLeft) {
      if (i > 0) {
        if (anUsed[i - 1] == false && anLength[i] == anLength[i - 1])
          continue;
      }
      anUsed[i] = 1;
      nLastStickNo = i;
      if (Dfs(nUnusedSticks - 1, nLeft - anLength[i]))
        return true;
      else {
        anUsed[i] = 0;
        if (anLength[i] == nLeft || nLeft == L)
          return false;
      }
    }
  }
  return false;
}
