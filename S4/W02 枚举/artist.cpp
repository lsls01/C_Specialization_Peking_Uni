#include<iostream>
#include<algorithm>

using namespace std;

void change(int a[][20], int n, int i, int j) {
  a[i][j]++;
  a[i][j] %= 2;
  a[i - 1][j]++;
  a[i - 1][j] %= 2;
  a[i + 1][j]++;
  a[i + 1][j] %= 2;
  a[i][j - 1]++;
  a[i][j - 1] %= 2;
  a[i][j + 1]++;
  a[i][j + 1] %= 2;
}

int fun(int a[][20], int n) {
  int ans = 0;
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 0) {
        ans++;
        change(a, n, i + 1, j);
      }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 0)
        return -1;
    }
  return ans;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int a[20][20] = {0};
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        char x;
        cin >> x;
        if (x == 'y')
          a[i][j] = 1;
        else
          a[i][j] = 0;
      }
    int ans = 0xffff;
    for (int k = 0; k <= n; k++) {
      int b[20][20] = {0};
      int tmp[20] = {0};
      for (int i = 0; i < k; i++) {
        tmp[n - i - 1] = 1;
      }
      do {
        for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++)
            b[i][j] = a[i][j];
        for (int i = 0; i < n; i++) {
          if (tmp[i] == 1)
            change(b, n, 1, i + 1);
        }
        int p = fun(b, n);
        if (p >= 0)
          ans = min(ans, k + p);
      } while (next_permutation(tmp, tmp + n));
    }
    if (ans == 0xffff)
      cout << "inf" << endl;
    else
      cout << ans << endl;
  }
}
