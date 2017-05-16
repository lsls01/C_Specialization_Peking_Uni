#include <cstdio>
#include <algorithm>

using namespace std;

unsigned long GetPartitionCount(int n, int max) {

  if (n == 1 || max == 1)
    return 1;
  else if (n < max)
    return GetPartitionCount(n, n);
  else if (n == max)
    return 1 + GetPartitionCount(n, max - 1);
  else
    return GetPartitionCount(n, max - 1) + GetPartitionCount(n - max, max);
}

int main() {
  int n, m;
  long ans;
  while (scanf("%d %d", &n, &m) != EOF) {
    ans = GetPartitionCount(n, m);
    printf("%ld\n", ans);
  }
  return 0;
}
