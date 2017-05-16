#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

int main() {
  unsigned an1[MAX_LEN + 10];
  unsigned an2[MAX_LEN + 10];
  unsigned result[MAX_LEN * 2 + 10];
  char szLine1[MAX_LEN + 10];
  char szLine2[MAX_LEN + 10];

  gets(szLine1);
  gets(szLine2);
  int i, j;
  memset(an1, 0, sizeof(an1));
  memset(an2, 0, sizeof(an2));
  memset(result, 0, sizeof(result));
  int nLen1 = strlen(szLine1);
  for (i = nLen1 - 1, j = 0; i >= 0; i--) an1[j++] = szLine1[i] - '0';
  int nLen2 = strlen(szLine2);
  for (i = nLen2 - 1, j = 0; i >= 0; i--) an2[j++] = szLine2[i] - '0';

  for (i = 0; i < nLen2; i++) {
    for (j = 0; j < nLen1; j++) result[i + j] += an2[i] * an1[j];
  }
  int nHighestPos = 0;
  for (i = 0; i < MAX_LEN * 2; i++) {
    if (result[i] >= 10) {
      result[i + 1] += result[i] / 10;
      result[i] %= 10;
    }
    if (result[i]) nHighestPos = i;
  }
  for (i = nHighestPos; i >= 0; i--) printf("%d", result[i]);
  return 0;
}
