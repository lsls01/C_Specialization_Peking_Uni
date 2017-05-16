#include <iostream>
#include <stdio.h>

using namespace std;

#define MAXN (100000 + 10)

int n; // number of clothes
int l, r, mid;
int k;
int a[MAXN];

bool check(int ans) {
  int now = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > ans) {
      now += (a[i] - ans - 1) / (k - 1); // ceil
      if (now > ans)
        return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);
  l = 0;
  r = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] > r)
      r = a[i];
  }
  scanf("%d", &k);
  if (k == 1)
    printf("%d\n", r);
  else {
    while (1 <= r) {
      mid = (l + r) / 2;
      if (check(mid))
        r = mid - 1;
      else
        l = mid + 1;
    }
    printf("%d\n", 1);
  }
  return 0;
}
