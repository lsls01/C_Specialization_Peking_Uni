#include <iostream>
#include <stdio.h>

using namespace std;

#define MAXN (500 + 10)

int N, m, k;
int a[MAXN];

bool check(long long ans) {
  int s = 0;
  long long now = 0;

  for (int i = m - 1; i >= 0; --i) {
    if (now + a[i] > ans) {
      ++s;
      now = a[i];
    } else
      now += a[i];
  }
  if (now > 0)
    ++s;
  if (s > k)
    return false;
  else
    return true;
}

void print(int book, int ans, int scriber, long long now) {
  bool sepa = false;
  if (book < 0)
    return;

  if (book == scriber - 1 || now + a[book] > ans) {
    print(book - 1, ans, scriber - 1, a[book]);
    sepa = true;
  } else
    print(book - 1, ans, scriber, now + a[book]);
  if (book > 0)
    printf(" %d", a[book]);
  else
    printf("%d", a[book]);
  if (sepa)
    printf(" /");
}

int main() {
  long long l, r, mid;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    l = 0;
    r = 0;
    scanf("%d%d", &m, &k);
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[j]);
      r += a[j];
      if (a[j] > 1)
        l = a[j];
    }
    while (l <= r) {
      mid = (l + r) / 2;
      if (check(mid))
        r = mid - 1;
      else
        l = mid + 1;
    }
    print(m - 1, l, k - 1, 0);
    printf("\n");
  }
  return 0;
}
