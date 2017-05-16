#include <algorithm>
#include <cstdio>

using namespace std;

#define INF 0xfffffff

int n, c;
int pos[100010];

bool check(int d) {
  int last = 0;
  for (int i = 1; i < c; i++) {
    int cur = last + 1;
    while (cur < n && pos[cur] - pos[last] < d)
      cur++;
    if (cur == n)
      return false;
    last = cur;
  }
  return true;
}

int main() {
  while (~scanf("%d%d", &n, &c)) {
    for (int i = 0; i < n; i++)
      scanf("%d", &pos[i]);
    sort(pos, pos + n);

    int l = 0, r = INF;
    while ((r - l) > 1) {
      int mid = (l + r) >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    printf("%d\n", l);
  }
  return 0;
}
