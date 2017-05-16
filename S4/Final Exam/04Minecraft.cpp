#include <iostream>

using namespace std;

int n[1001];

void fun() {
  for (int k = 1; k <= 1000; k++) {
    int minArea = 1 << 31;
    for (int len = 1; len <= k; len++) {
      if (k % len == 0) {
        int maxWi = k / len;
        for (int wi = 1; wi <= maxWi; wi++) {
          if (maxWi % wi == 0) {
            int hi = maxWi / wi;
            int area = (len * wi + len * hi + wi * hi) * 2;
            if (minArea > area)
              minArea = area;
          }
        }
      }
    }
    n[k] = minArea;
  }
}

int main() {
  int c;
  cin >> c;
  fun();
  int i;
  while (c--) {
    cin >> i;
    cout << n[i] << endl;
  }
  return 0;
}
