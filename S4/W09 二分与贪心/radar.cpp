#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

#define MAXN (1000 + 10)

struct Node {
  double left, right;
};

int T, n, d;
Node s[MAXN];

bool operator<(const Node &a, const Node &b) { return a.left < b.left; }

int Solve() {
  int ans;
  double now;
  sort(s, s + n);
  ans = 1;
  now = s[0].right;
  for (int i = 1; i < n; ++i) {
    if (s[i].left <= now)
      now = min(now, s[i].right);
    else {
      ++ans;
      now = s[i].right;
    }
  }
  return ans;
}

int main() {
  int x, y;
  bool flag;

  T = 0;
  while (1) {
    ++T;
    scanf("%d%d", &n, &d);
    if (n == 0 && d == 0)
      break;
    flag = true;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &x, &y);
      if (y > d)
        flag = false;
      else {
        s[i].left = x - sqrt(d * d - y * y);
        s[i].right = x + sqrt(d * d - y * y);
      }
    }
    if (flag)
      printf("Case %d: %d\n", T, Solve());
    else
      printf("Case %d: -1\n", T);
  }
  return 0;
}
