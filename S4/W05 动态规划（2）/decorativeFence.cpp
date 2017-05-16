#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int UP = 0;
const int DOWN = 1;
const int MAXN = 25;
long long C[MAXN][MAXN][2];
// C[i][k][DOWN] is the number of plans start with kth shortest stick in S(i)

void Init(int n) {
  memset(C, 0, sizeof(C));
  C[1][1][UP] = C[1][1][DOWN] = 1;
  for (int i = 2; i <= n; ++i)
    for (int k = 1; k <= i; ++k) {
      for (int M = k; M < i; ++M)
        C[i][k][UP] += C[i - 1][M][DOWN];
      for (int N = 1; N < k - 1; ++N)
        C[i][k][UP] += C[i - 1][N][UP];
    }
}

void Print(int n, long long cc) {
  long long skipped = 0;
  int seq[MAXN];
  int used[MAXN];
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= n; ++i) {
    int k = 0;
    int No = 0;
    for (k = 1; k <= n; ++k) {
      skipped = 0;
      if (!used[k]) {
        ++No;
        if (i == 1)
          skipped = C[n][No][UP] + C[n][No][DOWN];
        else {
          if (k > seq[i - 1] && (i <= 2 || seq[i - 2] > seq[i - 1]))
            skipped = C[n - i + 1][No][DOWN];
          else if (k < seq[i - 1] && (i <= 2 || seq[i - 2] < seq[i - 1]))
            skipped = C[n - i + 1][No][UP];
        }
        if (skipped >= cc)
          break;
        else
          cc -= skipped;
      }
    }
    used[k] = true;
    seq[i] = k;
  }
  for (int i = 1; i <= n; ++i)
    if (i < n)
      printf("%d ", seq[i]);
    else
      printf("%d", seq[i]);
  printf("\n");
}

int main() {
  int T, n;
  long long c;
  Init(20);
  scanf("%d", &T);
  while (T--) {
    scanf("%d %lld", &n, &c);
    Print(n, c);
  }
  return 0;
}
